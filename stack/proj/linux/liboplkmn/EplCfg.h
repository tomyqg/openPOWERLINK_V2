/**
********************************************************************************
\file   EplCfg.h

\brief  Configuration options for openPOWERLINK MN library

This file contains the configuration options for the openPOWERLINK MN libary
on Linux.

*******************************************************************************/

/*------------------------------------------------------------------------------
Copyright (c) 2012, SYSTEC electronik GmbH
Copyright (c) 2014, Bernecker+Rainer Industrie-Elektronik Ges.m.b.H. (B&R)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holders nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
------------------------------------------------------------------------------*/

#ifndef _INC_eplcfg_H_
#define _INC_eplcfg_H_

#include <oplk/global.h>

//==============================================================================
// generic defines which for whole EPL Stack
//==============================================================================

#ifndef BENCHMARK_MODULES
#define BENCHMARK_MODULES                           0 //0xEE800042L
#endif

// Default debug level:
// Only debug traces of these modules will be compiled which flags are set in define DEF_DEBUG_LVL.
#ifndef DEF_DEBUG_LVL
#define DEF_DEBUG_LVL                               (0xC00000000L)
#endif

#undef FTRACE_DEBUG

/* assure that system priorities of hrtimer and net-rx kernel threads are set appropriate */
#define EPL_THREAD_PRIORITY_HIGH                    75
#define EPL_THREAD_PRIORITY_MEDIUM                  50
#define EPL_THREAD_PRIORITY_LOW                     49

// These macros define all modules which are included
#define CONFIG_INCLUDE_NMT_MN
#define CONFIG_INCLUDE_PDO
#define CONFIG_INCLUDE_SDOS
#define CONFIG_INCLUDE_SDOC
#define CONFIG_INCLUDE_SDO_ASND
#define CONFIG_INCLUDE_SDO_UDP
#define CONFIG_INCLUDE_VETH
#define CONFIG_INCLUDE_CFM

#define CONFIG_DLLCAL_QUEUE                         EPL_QUEUE_CIRCBUF


//==============================================================================
// Ethernet driver (Edrv) specific defines
//==============================================================================

// switch this define to TRUE if Edrv supports fast tx frames
#define EDRV_FAST_TXFRAMES                          FALSE

// switch this define to TRUE if Edrv supports early receive interrupts
#define EDRV_EARLY_RX_INT                           FALSE

// switch this define to TRUE if Edrv supports auto delay responses
#define EDRV_AUTO_RESPONSE_DELAY                    FALSE

// switch this define to TRUE to include Edrv diagnostic functions
#define EDRV_USE_DIAGNOSTICS                        FALSE

//==============================================================================
// Data Link Layer (DLL) specific defines
//==============================================================================

// switch this define to TRUE if Edrv supports fast tx frames
// and DLL shall pass PRes as ready to Edrv after SoC
#define EPL_DLL_PRES_READY_AFTER_SOC                FALSE

// switch this define to TRUE if Edrv supports fast tx frames
// and DLL shall pass PRes as ready to Edrv after SoA
#define EPL_DLL_PRES_READY_AFTER_SOA                FALSE

// activate PResChaining support on MN
#define EPL_DLL_PRES_CHAINING_MN                    TRUE

// CN supports PRes Chaining
#define EPL_DLL_PRES_CHAINING_CN                    FALSE

// time when CN processing the isochronous task (sync callback of application and cycle preparation)
#define EPL_DLL_PROCESS_SYNC                        EPL_DLL_PROCESS_SYNC_ON_SOC

// Disable deferred release of rx-buffers until EdrvPcap supports it
#define DLL_DEFERRED_RXFRAME_RELEASE_ISOCHRONOUS    FALSE
#define DLL_DEFERRED_RXFRAME_RELEASE_ASYNCHRONOUS   FALSE

//==============================================================================
// OBD specific defines
//==============================================================================

// switch this define to TRUE if Epl should compare object range
// automaticly
#define CONFIG_OBD_CHECK_OBJECT_RANGE               FALSE

// set this define to TRUE if there are strings or domains in OD, which
// may be changed in object size and/or object data pointer by its object
// callback function (called event kObdEvWrStringDomain)
#define CONFIG_OBD_USE_STRING_DOMAIN_IN_RAM         TRUE

#define CONFIG_OBD_USE_LOAD_CONCISEDCF              TRUE
#define CONFIG_OBD_DEF_CONCISEDCF_FILENAME          "mnobd.cdc"
#define EPL_CFM_CONFIGURE_CYCLE_LENGTH              TRUE

// Configure if the range from 0xA000 is used for mapping client objects.
// openCONFIGURATOR uses this range for mapping objects.
#define CONFIG_OBD_INCLUDE_A000_TO_DEVICE_PART      TRUE

//==============================================================================
// Timer module specific defines
//==============================================================================

// if TRUE the high resolution timer module will be used (must always be TRUE!)
#define EPL_TIMER_USE_HIGHRES                       TRUE

//==============================================================================
// SDO module specific defines
//==============================================================================

// increase the number of SDO channels, because we are master
#define SDO_MAX_CONNECTION_ASND                     100
#define MAX_SDO_SEQ_CON                             100
#define MAX_SDO_COM_CON                             100
#define SDO_MAX_CONNECTION_UDP                      50

#endif // _INC_eplcfg_H_
