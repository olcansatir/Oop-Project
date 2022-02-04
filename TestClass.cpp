#include "TestClass.h"

void TestClass::doTest()
{
	DepthCamera dc("camera1.txt");
	PointCloud pointCloud;
	PointCloud pointCloud2;
	pointCloud = dc.capture();
	dc.setFileName("camera2.txt");
	pointCloud2 = dc.capture();

	RadiusOutlierFilter rof(15);
	rof.filter(pointCloud);
	rof.filter(pointCloud2);

	PassThroughFilter ptfCam1(400, 0, 400, 0, 45, -45);
	PassThroughFilter ptfCam2(500, 0, 500, 0, 45, -45);

	ptfCam1.filter(pointCloud);
	ptfCam2.filter(pointCloud2);


	double firstCameraTr[3] = { 100,500,50 };
	double secondCameraTr[3] = { 550,150,50 };

	double firstCameraRot[3] = { 0,0,-90 };
	double secondCameraRot[3] = { 0,0,90 };

	Transform transform(firstCameraTr, firstCameraRot);
	pointCloud = transform.doTransform(pointCloud);
	transform.setTranslation(secondCameraTr);
	transform.setRotation(secondCameraRot);
	pointCloud2 = transform.doTransform(pointCloud2);

	PointCloud transformedPointCloud;
	transformedPointCloud = pointCloud + pointCloud2;

	PointCloudRecorder pcr("output.txt");
	pcr.save(transformedPointCloud);
}
