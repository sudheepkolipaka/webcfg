/*
 * Copyright 2020 Comcast Cable Communications Management, LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __WEBCFGCOMMON_H__
#define __WEBCFGCOMMON_H__

#include <stdint.h>


/*----------------------------------------------------------------------------*/
/*                                   Macros                                   */
/*----------------------------------------------------------------------------*/
#if defined(_COSA_BCM_MIPS_)
#define DEVICE_MAC                   "Device.DPoE.Mac_address"
#elif defined(PLATFORM_RASPBERRYPI)
#define DEVICE_MAC                   "Device.Ethernet.Interface.5.MACAddress"
#elif defined(RDKB_EMU)
#define DEVICE_MAC                   "Device.DeviceInfo.X_COMCAST-COM_WAN_MAC"
#else
#define DEVICE_MAC                   "Device.X_CISCO_COM_CableModem.MACAddress"
#endif

#define SERIAL_NUMBER                "Device.DeviceInfo.SerialNumber"
#define FIRMWARE_VERSION             "Device.DeviceInfo.X_CISCO_COM_FirmwareName"
#define DEVICE_BOOT_TIME             "Device.DeviceInfo.X_RDKCENTRAL-COM_BootTime"
#define MODEL_NAME		     "Device.DeviceInfo.ModelName"
#define PRODUCT_CLASS		     "Device.DeviceInfo.ProductClass"
/*----------------------------------------------------------------------------*/
/*                               Data Structures                              */
/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/
/*                             External Functions                             */
/*----------------------------------------------------------------------------*/
/* return logger file name */
const char *fetch_generic_file(void);
void get_webCfg_interface(char **interface);
int getConfigVersion(int index, char **version);
bool getConfigURL(int index, char **url);
bool getRequestTimeStamp(int index,char **RequestTimeStamp);
int setRequestTimeStamp(int index);
int setSyncCheckOK(int index, bool status);
int setConfigVersion(int index, char *version);
int setSyncCheckOK(int index, bool status);

char *get_global_systemReadyTime();
void getCurrentTime(struct timespec *timer);
char * getParameterValue(char *paramName);
void getDeviceMac();
char* get_global_deviceMAC();

void sendNotification(char *payload, char *source, char *destination);
#endif
