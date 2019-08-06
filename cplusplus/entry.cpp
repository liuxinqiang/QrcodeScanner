#include <iostream>
#include <node_api.h>
#include "qrcode/qrcode.h"


napi_value init(napi_env env, napi_value exports) {
	napi_value localFuncList[1];

	napi_create_function(env, nullptr, 0, ScanImage, nullptr, localFuncList);

	napi_set_named_property(env, exports, "scanImage", localFuncList[0]);

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init);