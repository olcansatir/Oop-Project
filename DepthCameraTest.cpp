#include "PointCloudRecorder.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include "PointCloudGenerator.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
//This class is defined to pass the test operation of the DepthCamera class

int main()
{
	//FilterPipe object for first camera
	FilterPipe filterPipeFirstCamera;
	filterPipeFirstCamera.addFilter(new RadiusOutlierFilter(25));
	filterPipeFirstCamera.addFilter(new PassThroughFilter(400, 0, 400, 0, 45, -45));
	//FilterPipe object for second camera
	FilterPipe filterPipeSecondCamera;
	filterPipeSecondCamera.addFilter(new RadiusOutlierFilter(25));
	filterPipeSecondCamera.addFilter(new PassThroughFilter(500, 0, 500, 0, 45, -45));

	//Camera translations and rotations arrays
	Eigen::Vector3d firstCameraTr;
	Eigen::Vector3d secondCameraTr;
	firstCameraTr << 100, 500, 50;
	secondCameraTr << 550, 150, 50;

	Eigen::Vector3d firstCameraRot;
	Eigen::Vector3d secondCameraRot;
	firstCameraRot << 0, 0, -90;
	secondCameraRot << 0, 0, 90;

	//Transform object for first and second camera
	Transform transformForFirstCamera(firstCameraTr, firstCameraRot);
	Transform transformForSecondCamera(secondCameraTr, secondCameraRot);

	// Opening the file
	DepthCamera depthCamera("camera1.txt", transformForFirstCamera, &filterPipeFirstCamera);
	PointCloud pointCloud;
	pointCloud = depthCamera.capture();
	pointCloud.printPoints();
}