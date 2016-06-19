// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2015 Intel Corporation. All Rights Reserved.

#pragma once
#ifndef LIBREALSENSE_SR300_H
#define LIBREALSENSE_SR300_H

#include <atomic>
#include "ivcam-private.h"
#include "ivcam-device.h"

#define SR300_PRODUCT_ID 0x0aa5

namespace rsimpl
{

    class sr300_camera final : public iv_camera
    {

        sr300::wakeup_dev_params arr_wakeup_dev_param;

    public:
        sr300_camera(std::shared_ptr<uvc::device> device, const static_device_info & info, const ivcam::camera_calib_params & calib);
        ~sr300_camera() {};

        void set_options(const rs_option options[], size_t count, const double values[]) override;
        void get_options(const rs_option options[], size_t count, double values[]) override;

    };

    std::shared_ptr<rs_device> make_sr300_device(std::shared_ptr<uvc::device> device);
}

#endif
