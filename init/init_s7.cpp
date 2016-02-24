/*
   Copyright (c) 2016, The AOSParadox Project. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

//Samsung Galaxy S7: G930F (Global); G930FD (Southeast Asia)
//Samsung Galaxy S7 (CDMA): G930A (AT&T, Cricket); G930P (Sprint, Boost, Virgin Mobile); G930V (Verizon); G930T (T-Mobile, Metro PCS); G930R (US Cellular)

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G930F")) {
        /* G930F (Global) */
        property_set("ro.product.model", "SM-G930F");
    } else if (strstr(bootloader, "G930FD")) {
        /* G930FD (Southeast Asia) */
        property_set("ro.product.model", "SM-G930FD");
    } else if (strstr(bootloader, "G930A")) {
        /* G930A (AT&T, Cricket) */
        property_set("ro.product.model", "SM-G930A");
    } else if (strstr(bootloader, "G930P")) {
        /* G930P (Sprint, Boost, Virgin Mobile) */
        property_set("ro.product.model", "SM-G930P");
        property_set("ro.cdma.home.operator.alpha", "Chameleon");
        property_set("ro.cdma.home.operator.numeric", "310000");
        property_set("ro.com.google.clientidbase.ms", "android-sprint-mvno-us");
        property_set("ro.com.google.clientidbase.am", "android-sprint-mvno-us");
        property_set("ro.com.google.clientidbase.yt", "android-sprint-mvno-us");
    } else if (strstr(bootloader, "G930V")) {
        /* G930V (Verizon) */
        property_set("ro.product.model", "SM-G930V");
        property_set("ro.cdma.home.operator.alpha", "Verizon");
        property_set("ro.cdma.home.operator.numeric", "310004");
        property_set("ro.com.google.clientidbase.ms", "android-verizon");
        property_set("ro.com.google.clientidbase.am", "android-verizon");
        property_set("ro.com.google.clientidbase.yt", "android-verizon");
    } else if (strstr(bootloader, "G930T")) {
        /* G930T (T-Mobile, Metro PCS) */
        property_set("ro.product.model", "SM-G930T");
    } else if (strstr(bootloader, "G930R")) {
        /* G930R (US Cellular) */
        property_set("ro.product.model", "SM-G930R");
        property_set("ro.cdma.home.operator.numeric", "311220");
        property_set("gsm.sim.operator.numeric", "311580");
        property_set("ro.cdma.home.operator.alpha", "U.S. Cellular");
        property_set("ro.com.google.clientidbase.ms", "android-uscellular-us");
        property_set("ro.com.google.clientidbase.am", "android-uscellular-us");
        property_set("ro.com.google.clientidbase", "android-samsung");
        property_set("ro.com.google.clientidbase.gmm", "android-samsung");
        property_set("ro.com.google.clientidbase.yt", "android-samsung");
    } else {
        /* G930F (Global) */
        property_set("ro.product.model", "SM-G930F");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
