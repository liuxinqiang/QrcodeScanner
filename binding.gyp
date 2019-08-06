{
    "targets": [
        {
            "target_name": "qrcode_scanner",
            "sources": [
                "cplusplus/entry.cpp",
                "cplusplus/qrcode/qrcode.cpp"
            ],
			"conditions": [
				['OS=="win"', {
					"include_dirs": [
						"./lib/opencv/include",
						"./lib/zbar/include"
					],
					"link_settings": {
						 "libraries": [
							"../lib/opencv/lib/opencv_world345",
							"../lib/zbar/lib/libzbar64-0"
						 ],
					}
				}],
				['OS=="mac"', {
				}],
				['OS=="linux"', {
				}],
			]
        }
    ]
}