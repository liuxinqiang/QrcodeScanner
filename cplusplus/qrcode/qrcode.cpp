#include "qrcode.h"

napi_value ScanImage(napi_env env, napi_callback_info info) {

	zbar::ImageScanner scanner;

	scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

	// obtain image data  
	cv::Mat img = cv::imread("18.jpg", 0);
	cv::Mat imgout;
	cv::cvtColor(img, imgout, CV_GRAY2RGB);

	int width = img.cols;
	int height = img.rows;
	uchar *raw = (uchar *)img.data;

	// wrap image data  
	zbar::Image image(width, height, "Y800", raw, width * height);

	// scan the image for barcodes  
	int n = scanner.scan(image);

	// extract results  
	for (zbar::Image::SymbolIterator symbol = image.symbol_begin();
		symbol != image.symbol_end();
		++symbol) {
		std::vector<cv::Point> vp;

		// do something useful with results  
		std::cout
			<< "decoded "
			<< symbol->get_type_name()
			<< " symbol \"" << symbol->get_data()
			<< '"'
			<< " "
			<< std::endl;

		int n = symbol->get_location_size();

		for (int i = 0; i < n; i++) {
			vp.push_back(cv::Point(symbol->get_location_x(i), symbol->get_location_y(i)));
		}

		cv::RotatedRect r = minAreaRect(vp);

		cv::Point2f pts[4];

		r.points(pts);

		for (int i = 0; i < 4; i++) {
			line(imgout, pts[i], pts[(i + 1) % 4], cv::Scalar(255, 0, 0), 3);
		}

		std::cout << "Angle: " << r.angle << std::endl;
	}
	imshow("imgout.jpg", imgout);

	// clean up  
	image.set_data(NULL, 0);

	cv::waitKey();

	napi_value result;

	napi_create_string_utf8(env, "Hello World", NAPI_AUTO_LENGTH, &result);

	return result;
}