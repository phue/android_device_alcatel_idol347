#
# Copyright (C) 2014 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Inherit from idol347
$(call inherit-product, device/alcatel/idol347/device.mk)

# Device identifier. This must come after all inclusions
PRODUCT_DEVICE := idol347
PRODUCT_NAME := full_idol347
PRODUCT_BRAND := alcatel
PRODUCT_MODEL := idol347
PRODUCT_MANUFACTURER := alcatel
$(call inherit-product-if-exists, vendor/alcatel/idol347/idol347-vendor.mk)
