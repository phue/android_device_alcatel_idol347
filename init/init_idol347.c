/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.
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

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void common_properties()
{
        property_set("ro.product.device", "idol347");
        property_set("ro.build.product", "idol347");
}

void dualsim_properties(char multisim_config[])
{
    property_set("persist.radio.multisim.config", multisim_config);
}

void gsm_properties(char default_network[])
{
    property_set("ro.telephony.default_network", default_network);
}

void tct_properties(char tct_product[])
{
    property_set("ro.tct.product", tct_product);
}


void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char variant[PROP_VALUE_MAX]; 
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || strncmp(platform, ANDROID_TARGET, PROP_VALUE_MAX))
        return;

    property_get("ro.cm.variant", variant);
    
    if (strstr(variant, "6039Y")) {
        /* 6039Y L1AJE0E0BQ00 */
        common_properties();
        dualsim_properties("single");
        gsm_properties("9");
        tct_properties("idol347");
        property_set("ro.build.fingerprint", "TCL/6039Y/idol347:5.0.2/LRX22G/v1AJE-0:user/release-keys");
        property_set("ro.build.description", "idol347-user 5.0.2 LRX22G v1AJE-0 release-keys");
        property_set("ro.product.model", "6039Y");
    } else if (strstr(variant, "6039A")) {
       /* 6039A L1ACM0M0BQ00 */
        common_properties();
        dualsim_properties("single");
        gsm_properties("9");
        tct_properties("idol347");
        property_set("ro.build.fingerprint", "TCL/6039A/idol347:5.0.2/LRX22G/v1ACM-0:user/release-keys");
        property_set("ro.build.description", "idol347-user 5.0.2 LRX22G v1ACM-0 release-keys");
        property_set("ro.product.model", "6039A");
    } else if (strstr(variant, "6039S")) {
       /* 6039S L1ACV0V0BQ00 */
        common_properties();
        dualsim_properties("single");
        gsm_properties("9");
        tct_properties("idol347");
        property_set("ro.build.fingerprint", "TCL/6039S/idol347:5.0.2/LRX22G/v1ACV-0:user/release-keys");
        property_set("ro.build.description", "idol347-user 5.0.2 LRX22G v1ACV-0 release-keys");
        property_set("ro.product.model", "6039S");
    } else if (strstr(variant, "6039K")) {
       /* 6039K L1AJE0E0BQ00 */
        common_properties();
        dualsim_properties("dsds");
        gsm_properties("9");
        tct_properties("idol347");
        property_set("ro.build.fingerprint", "TCL/6039K/idol347:5.0.2/LRX22G/v1AEY-0:user/release-keys");
        property_set("ro.build.description", "idol347-user 5.0.2 LRX22G v1AEY-0 release-keys");
        property_set("ro.product.model", "6039K");
    } else {
        /* 6039X */
        common_properties();
        dualsim_properties("single");
        gsm_properties("9");
        tct_properties("idol347");
        property_set("ro.build.fingerprint", "TCL/6039X/idol347:5.0.2/LRX22G/v1XXX-0:user/release-keys");
        property_set("ro.build.description", "idol347-user 5.0.2 LRX22G v1XXX-0 release-keys");
        property_set("ro.product.model", "6039X");
    }

    property_get("ro.product.device", device);
    ERROR("Found device variant %s setting build properties for %s device\n", variant, device);
}
