#include "PointCloudRecorder.h"
#include "PointCloud.h"
#include "DepthCamera.h"
int main()
{
	PointCloud pointCloud(5);
	pointCloud.setSinglePoint(0, 1,6, 3);
	pointCloud.setSinglePoint(1, 64, 1,7);
	pointCloud.setSinglePoint(2, 18, 2, 6);
	pointCloud.setSinglePoint(3, 14,24, 64);
	pointCloud.setSinglePoint(4, 78, 72, 67);

	PointCloudRecorder Pcr("Save.txt");
	Pcr.save(pointCloud);






}