void makeStar()
{


	cv::circle(src, cv::Point(200, 200), 2, 255);
	int cnt = 0;
	for (float i = 0; i < 360; i = i + 15)
	{
		Point pt;
		cnt++;

		if (cnt % 3 == 0)
		{
			pt.x = 200 + 100 * cos(i * (3.14 / 180.0));
			pt.y = 200 + 100 * sin(i * (3.14 / 180.0));
			cv::circle(src, pt, 2, 255);
			vecPt.push_back(pt);
		}
		else
		{
		
			pt.x = 200 + 50 * cos(i * (3.14 / 180.0));
			pt.y = 200 + 50 * sin(i * (3.14 / 180.0));
			cv::circle(src, pt, 2, 255);
			vecPt.push_back(pt);
		
		}
		
		if (i == 0)
		{
			firstPt.x = pt.x;
			firstPt.y = pt.y;
		}
		//line(src, vert[i], vert[(i + 1) % 6], Scalar(255), 3);
	}
	vecPt.push_back(firstPt);

	int distm = 0;
	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			int pttest = cv::pointPolygonTest(vecPt, Point(i, j), distm);
			if (pttest == 0)
			{
				cv::circle(src, Point(i, j), 1, cv::Scalar(255, 0, 0));
			}
			else if (pttest == 1)
			{
				cv::circle(src, Point(i, j), 2, cv::Scalar(0, 255, 0));
			}
			else if (pttest == -1)
			{
				cv::circle(src, Point(i, j), 2, cv::Scalar(0, 0, 255));
			}
		}
	}
	namedWindow("PolygonTest", 1);
	//set the callback function for any mouse event
	setMouseCallback("PolygonTest", CallBackFunc);
	cv::imshow("PolygonTest", src);
	cv::waitKey(0);

}
