#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

int
main (int argc, char** argv)
{
  pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2 ());
  pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

  // Read the existing cloud 
  pcl::PCDReader reader;
  reader.read ("MedianSpike_5.pcd", *cloud);

  // Create the filtering object
  pcl::StatisticalOutlierRemoval<pcl::PCLPointCloud2> statFil;
  statFil.setInputCloud (cloud);
  statFil.setMeanK (50);
  statFil.setStddevMulThresh (1.0);
  statFil.filter (*cloud_filtered);

  pcl::PCDWriter writer;
  writer.write ("MedianSpike_5_downsampled.pcd", *cloud_filtered,
         Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);

  return (0);
}
