/******************************************************************************
*
* (c) Copyright 2013, Freescale
*
******************************************************************************/
/*!
*
* @file       GFLIB_Atan.h
*
* @version    1.0.1.0
*
* @date       Oct-9-2013
*
* @brief      Header file for GFLIB_Atan function
*
******************************************************************************/
#ifndef GFLIB_ATAN_H
#define GFLIB_ATAN_H

#ifdef __cplusplus
extern "C" {
#endif

/**
* @page misra_violations MISRA-C:2004 violations
*
* @section GFLIB_Atan_h_REF_1
* Violates MISRA 2004 Required Rule 19.4, Disallowed definition for macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of disallowed macro
* definition.
*
* @section GFLIB_Atan_h_REF_2
* Violates MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires the function-like macro
* definition.
*
* @section GFLIB_Atan_h_REF_3
* Violates MISRA 2004 Required Rule 19.10, Unparenthesized macro parameter in definition of macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of unparenthesized
* macro parameters.
*
* @section GFLIB_Atan_h_REF_4
* Violates MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
* To allow the user utilize the benefits of using all three supported implementation of each
* function in user application, the macro dispatcher inevitably requires use of '#/##' operators.
*/
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"
#include "SWLIBS_MacroDisp.h"
#include "mlib.h"

/****************************************************************************
* Defines and macros            (scope: module-local)
****************************************************************************/
#ifndef  _MATLAB_BAM_CREATE
  /*
  * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GFLIB_Atan(...)     macro_dispatcher(GFLIB_Atan, __VA_ARGS__)(__VA_ARGS__)     /*!< This function implements polynomial approximation of arctangent function. */

  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F32)
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    */
    #define GFLIB_ATAN_T                        GFLIB_ATAN_T_F32                            /*!< Definition of GFLIB_ATAN_T as alias for GFLIB_ATAN_T_F32 datatype in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    */
    #define GFLIB_ATAN_DEFAULT                  GFLIB_ATAN_DEFAULT_F32                      /*!< Definition of GFLIB_ATAN_DEFAULT as alias for GFLIB_ATAN_DEFAULT_F32 default value in case the 32-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    #define GFLIB_Atan_Dsptchr_2(In,pParam)     GFLIB_Atan_Dsptchr_3(In,pParam,F32)         /*!< Function dispatcher for GFLIB_Atan_Dsptchr_2, do not modify!!! */
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00074 */
    #define GFLIB_Atan_Dsptchr_1(In)            GFLIB_Atan_Dsptchr_2(In,GFLIB_ATAN_DEFAULT) /*!< Function dispatcher for GFLIB_Atan_Dsptchr_1, do not modify!!! */
  #endif
  #if (SWLIBS_DEFAULT_IMPLEMENTATION == SWLIBS_DEFAULT_IMPLEMENTATION_F16)
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    */
    #define GFLIB_ATAN_T                        GFLIB_ATAN_T_F16                            /*!< Definition of GFLIB_ATAN_T as alias for GFLIB_ATAN_T_F16 datatype in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    */
    #define GFLIB_ATAN_DEFAULT                  GFLIB_ATAN_DEFAULT_F16                      /*!< Definition of GFLIB_ATAN_DEFAULT as alias for GFLIB_ATAN_DEFAULT_F16 default value in case the 16-bit fractional implementation is selected. */
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    #define GFLIB_Atan_Dsptchr_2(In,pParam)     GFLIB_Atan_Dsptchr_3(In,pParam,F16)         /*!< Function dispatcher for GFLIB_Atan_Dsptchr_2, do not modify!!! */
    /*
    * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
    * macro.
    * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
    * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
    * parameter in definition of macro.
    */
    /** @remarks Implements DGFLIB00074 */
    #define GFLIB_Atan_Dsptchr_1(In)            GFLIB_Atan_Dsptchr_2(In,GFLIB_ATAN_DEFAULT) /*!< Function dispatcher for GFLIB_Atan_Dsptchr_1, do not modify!!! */
  #endif

  /*
  * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  */
  #define GFLIB_Atan_Dsptchr_3(In,pParam,Impl)    GFLIB_Atan_Dsptchr_(In,pParam,Impl)     /*!< Function dispatcher for GFLIB_Atan_Dsptchr_3, do not modify!!! */

  /*
  * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  * @violates @ref GFLIB_Atan_h_REF_2 MISRA 2004 Advisory Rule 19.7, Function-like macro defined.
  * @violates @ref GFLIB_Atan_h_REF_3 MISRA 2004 Required Rule 19.10, Unparenthesized macro
  * parameter in definition of macro.
  * @violates @ref GFLIB_Atan_h_REF_4 MISRA 2004 Advisory Rule 19.13, #/##' operator used in macro.
  */
  /** @remarks Implements DGFLIB00076 */
  #define GFLIB_Atan_Dsptchr_(In,pParam,Impl)     GFLIB_Atan_##Impl(In,pParam)            /*!< Function dispatcher for GFLIB_Atan_Dsptchr_, do not modify!!! */
#endif

/****************************************************************************
* Typedefs and structures       (scope: module-local)
****************************************************************************/




/****************************************************************************
* Implementation variant: 32-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON)
  /*
  * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  */
  #define GFLIB_ATAN_DEFAULT_F32 &f32gflibAtanCoef     /*!< Default approximation coefficients for GFLIB_Atan_F32 function. */

  /************************************************************************/
  /*!
  @struct GFLIB_ATAN_TAYLOR_COEF_T_F32 "\GFLIB_Atan.h"

  @brief  Array of minimax polynomial approximation coefficients for one sub-interval.

  @details  Output of arctan(f32In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Minimax polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Three coefficients for a single sub-interval are stored in this (#GFLIB_ATAN_TAYLOR_COEF_T_F32)
            structure.
  *//**********************************************************************/
  typedef struct{
	  const Frac32  f32A[3];
  }GFLIB_ATAN_TAYLOR_COEF_T_F32;

  /************************************************************************/
  /*!
  @struct GFLIB_ATAN_T_F32 "\GFLIB_Atan.h"

  @brief    Structure containing eight sub-structures with polynomial coefficients to cover all sub-intervals.

  @details  Output of arctan(f32In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Eight arrays, each including three polynomial coefficients for each sub-interval, are stored
            in this (#GFLIB_ATAN_T_F32) structure.
  *//**********************************************************************/
  typedef struct{
    const GFLIB_ATAN_TAYLOR_COEF_T_F32  GFLIB_ATAN_SECTOR[8];
  }GFLIB_ATAN_T_F32;

  /************************************************************************/
  /*!
  @brief  Default approximation coefficients for arctangent approximation.
  *//**********************************************************************/

  extern const GFLIB_ATAN_T_F32 f32gflibAtanCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern Frac32 GFLIB_Atan_F32(Frac32 f32In,const GFLIB_ATAN_T_F32 *const pParam);
#endif /* SWLIBS_SUPPORT_F32 == SWLIBS_STD_ON */




/****************************************************************************
* Implementation variant: 16-bit fractional
****************************************************************************/
#if (SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON)
  /*
  * @violates @ref GFLIB_Atan_h_REF_1 MISRA 2004 Required Rule 19.4, Disallowed definition for
  * macro.
  */
  #define GFLIB_ATAN_DEFAULT_F16 &f16gflibAtanCoef     /*!< Default approximation coefficients for GFLIB_Atan_F16 function. */

  /************************************************************************/
  /*!
  @struct GFLIB_ATAN_TAYLOR_COEF_T_F16 "\GFLIB_Atan.h"

  @brief  Array of polynomial approximation coefficients for one sub-interval.

  @details  Output of arctan(f16In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Three coefficients for a single sub-interval are stored in this (#GFLIB_ATAN_TAYLOR_COEF_T_F16)
            structure.
  *//**********************************************************************/
  typedef struct{
	  const Frac16  f16A[3];
  }GFLIB_ATAN_TAYLOR_COEF_T_F16;

  /************************************************************************/
  /*!
  @struct GFLIB_ATAN_T_F16 "\GFLIB_Atan.h"

  @brief    Structure containing eight sub-structures with polynomial coefficients to cover all sub-intervals.

  @details  Output of arctan(f16In) for interval [0, 1) of the input ratio is divided
            into eight sub-sectors. Polynomial approximation is done using a 3rd order polynomial, for each sub-sector
            respectively. Eight arrays, each including three polynomial coefficients for each sub-interval, are stored
            in this (#GFLIB_ATAN_T_F16) structure.
  *//**********************************************************************/
  typedef struct{
    const GFLIB_ATAN_TAYLOR_COEF_T_F16  GFLIB_ATAN_SECTOR[8];
  }GFLIB_ATAN_T_F16;

  /************************************************************************/
  /*!
  @brief  Default approximation coefficients for arctangent approximation.
  *//**********************************************************************/

  extern const GFLIB_ATAN_T_F16 f16gflibAtanCoef;

/****************************************************************************
* Exported function prototypes
****************************************************************************/
  extern Frac16 GFLIB_Atan_F16(Frac16 f16In,const GFLIB_ATAN_T_F16 *const pParam);
#endif /* SWLIBS_SUPPORT_F16 == SWLIBS_STD_ON */




#ifdef __cplusplus
}
#endif

#endif /* GFLIB_ATAN_H */
