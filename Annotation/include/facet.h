/****************************************************************************
*   AnnotationTransfer                                                      *
*   Authors: Andrea Repetto & Andreas Scalas                                *
*   Copyright (C) 2018  IMATI-GE / CNR                                      *
*   All rights reserved.                                                    *
*                                                                           *
*   This program is free software: you can redistribute it and/or modify    *
*   it under the terms of the GNU General Public License as published by    *
*   the Free Software Foundation, either version 3 of the License, or       *
*   (at your option) any later version.                                     *
*                                                                           *
*   This program is distributed in the hope that it will be useful,         *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
*   GNU General Public License for more details.                            *
*                                                                           *
*   You should have received a copy of the GNU General Public License       *
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
****************************************************************************/

#ifndef FACET_H
#define FACET_H

#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <map>
#include <string>

std::string trim(const std::string &str);

class fct_parse_error : public std::runtime_error
{
public:
    fct_parse_error(std::string __arg) :
        std::runtime_error(__arg)
    {
    }
};

class fct_write_error : public std::runtime_error
{
public:
    fct_write_error(std::string __arg) :
        std::runtime_error(__arg)
    {
    }
};

struct Facet
{
    enum class FacetType
    {
        INTERNAL,
        EXTERNAL,
        FRACTURE,
        UNKNOWN
    };


    // The label of the facet, typically a string containing an integer number
    std::string label;

    // List of boundaries, each one containing the ids of its vertices
    std::vector<std::vector<int> > boundaries;

    // Indices of the inner vertices
    std::vector<int> innerVertices;

    // The facet type
    FacetType type;

};

class FacetReader
{

    public:

        FacetReader();

        bool readFct(const std::string &filename);

        std::vector<Facet> getFacets();

        std::string getFilename() const;

    private:
        void readHeader(std::fstream &fs);

        void readFacet(std::fstream &fs);

        std::string readField(std::istream &fs, const std::string &regex, int matchIndex = 1);

        void readExact(std::istream &fs, const std::string &match_str);

        template <typename T>
        std::vector<T> readVector(std::istream &fs)
        {
            try
            {
                std::string line;

                std::getline(fs, line);

                std::istringstream ss(line);

                std::vector<T> out;

                T value;

                if(line.compare("Vertices:") == 0)
                    return out;

                while(ss >> value)
                {
                    out.push_back( value - T(1) );
                }

                return out;
            }
            catch(std::exception &e)
            {
                throw fct_parse_error("ERROR Could not read vector input");
            }
        }

        Facet::FacetType strToFacetType(std::string &value);

        std::string m_filename;

        std::vector<Facet> m_facets;

        int m_numFacets = 0;

        std::map<std::string, Facet::FacetType> m_facetTypeMap =
        {
            { "external", Facet::FacetType::EXTERNAL },
            { "internal", Facet::FacetType::INTERNAL},
            { "fracture", Facet::FacetType::FRACTURE },
        };

};

class FacetWriter
{
    public:

        FacetWriter();

        bool writeFct(const std::string &filename);

        void setFacets(std::vector<Facet>);

        void setFilename(const std::string &filename);

    private:
        void writeHeader(std::fstream &fs);

        void writeFacet(std::fstream &fs);

        void writeField(std::ostream &fs, const std::string field);

        void writeExact(std::ostream &fs, const std::string &match_str);

        template <typename T>
        void writeVector(std::ostream &fs, std::vector<T> vect)
        {
            try
            {
                for(int i = 0; i < vect.size(); i++)
                    fs<<vect[i]+1<<" ";
            }
            catch(std::exception &e)
            {
                throw fct_parse_error("ERROR Could not read vector input");
            }
        }

        std::string facetTypeToString(Facet::FacetType &value);

        std::string m_filename;

        std::vector<Facet> m_facets;

        int m_numFacets;

        std::map<Facet::FacetType,std::string> m_facetTypeMap;
};

#endif // FACET_H
