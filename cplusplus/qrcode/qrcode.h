#include <iostream>
#include <node_api.h>
#include <opencv2/opencv.hpp>
#include "zbar.h"

napi_value ScanImage(napi_env, napi_callback_info);