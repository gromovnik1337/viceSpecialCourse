#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/cloud_viewer.h>

int
main (int argc, char** argv)
{
  //Define XYZ point cloud object
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

  // Load the file
  if (pcl::io::loadPCDFile<pcl::PointXYZ> ("RawRaw_stat_5.pcd", *cloud) == -1)
  {
    PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
    return (-1);
  }

  std::cout << "Loaded "
            << cloud->width * cloud->height
            << " data points from loaded point cloud with the following fields: "
            << std::endl;

  // Visualize the cloud
  pcl::visualization::CloudViewer viewer ("Simple Cloud Viewer");
  viewer.showCloud (cloud);
  while (!viewer.wasStopped ())
  {
  }

  return (0);
}
