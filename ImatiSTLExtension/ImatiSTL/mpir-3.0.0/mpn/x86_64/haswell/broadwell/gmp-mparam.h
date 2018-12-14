/* Generated by tuneup.c, 2017-02-15, gcc 5.4 */

#define MUL_KARATSUBA_THRESHOLD          16
#define MUL_TOOM3_THRESHOLD              86
#define MUL_TOOM4_THRESHOLD             152
#define MUL_TOOM8H_THRESHOLD            327

#define SQR_BASECASE_THRESHOLD            0  /* always (native) */
#define SQR_KARATSUBA_THRESHOLD          26
#define SQR_TOOM3_THRESHOLD              90
#define SQR_TOOM4_THRESHOLD             256
#define SQR_TOOM8_THRESHOLD             462

#define DIVREM_1_NORM_THRESHOLD       MP_SIZE_T_MAX  /* never */
#define DIVREM_1_UNNORM_THRESHOLD     MP_SIZE_T_MAX  /* never */
#define MOD_1_NORM_THRESHOLD              0  /* always */
#define MOD_1_UNNORM_THRESHOLD            0  /* always */
#define USE_PREINV_DIVREM_1               1  /* native */
#define USE_PREINV_MOD_1                  1
#define DIVEXACT_1_THRESHOLD              0  /* always */
#define MODEXACT_1_ODD_THRESHOLD          0  /* always (native) */
#define MOD_1_1_THRESHOLD                 6
#define MOD_1_2_THRESHOLD                 8
#define MOD_1_3_THRESHOLD                13
#define DIVREM_HENSEL_QR_1_THRESHOLD     38
#define RSH_DIVREM_HENSEL_QR_1_THRESHOLD      4
#define DIVREM_EUCLID_HENSEL_THRESHOLD     33

#define MUL_FFT_FULL_THRESHOLD         5952

#define SQR_FFT_FULL_THRESHOLD         3520

#define MULLOW_BASECASE_THRESHOLD         0  /* always */
#define MULLOW_DC_THRESHOLD              48
#define MULLOW_MUL_THRESHOLD            114

#define MULMID_TOOM42_THRESHOLD          24

#define MULHIGH_BASECASE_THRESHOLD        8
#define MULHIGH_DC_THRESHOLD             53
#define MULHIGH_MUL_THRESHOLD          2966

#define MULMOD_2EXPM1_THRESHOLD          16

#define DC_DIV_QR_THRESHOLD              68
#define INV_DIV_QR_THRESHOLD           2172
#define INV_DIVAPPR_Q_N_THRESHOLD        68
#define DC_DIV_Q_THRESHOLD               83
#define INV_DIV_Q_THRESHOLD            1752
#define DC_DIVAPPR_Q_THRESHOLD          128
#define INV_DIVAPPR_Q_THRESHOLD       19313
#define DC_BDIV_QR_THRESHOLD             78
#define DC_BDIV_Q_THRESHOLD             110

#define BINV_NEWTON_THRESHOLD            30
#define REDC_1_TO_REDC_2_THRESHOLD       22
#define REDC_2_TO_REDC_N_THRESHOLD       56

#define ROOTREM_THRESHOLD                 6

#define MATRIX22_STRASSEN_THRESHOLD      17
#define HGCD_THRESHOLD                  115
#define HGCD_APPR_THRESHOLD             112
#define HGCD_REDUCE_THRESHOLD          6852
#define GCD_DC_THRESHOLD                767
#define GCDEXT_DC_THRESHOLD             487
#define JACOBI_BASE_METHOD                2

#define GET_STR_DC_THRESHOLD             14
#define GET_STR_PRECOMPUTE_THRESHOLD     20
#define SET_STR_DC_THRESHOLD           1623
#define SET_STR_PRECOMPUTE_THRESHOLD   3037

#define FAC_DSC_THRESHOLD               662
#define FAC_ODD_THRESHOLD                44

/* fft_tuning -- autogenerated by tune-fft */

#define FFT_TAB \
   { { 4, 3 }, { 4, 3 }, { 3, 2 }, { 2, 1 }, { 1, 0 } }

#define MULMOD_TAB \
   { 4, 4, 4, 4, 4, 3, 3, 3, 3, 2, 3, 3, 3, 2, 2, 2, 2, 1, 1 }

#define FFT_N_NUM 19

#define FFT_MULMOD_2EXPP1_CUTOFF 256


/* Tuneup completed successfully, took 101 seconds */

