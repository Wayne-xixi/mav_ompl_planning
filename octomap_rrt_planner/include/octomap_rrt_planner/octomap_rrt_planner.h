//  June/2019, ETHZ, Jaeyoung Lim, jalim@student.ethz.ch

#ifndef OCTOMAP_RRT_PLANNER_H
#define OCTOMAP_RRT_PLANNER_H

#include <ros/ros.h>
#include <ros/subscribe_options.h>
#include <tf/transform_broadcaster.h>

#include <stdio.h>
#include <cstdlib>
#include <string>
#include <sstream>

#include <Eigen/Dense>

#include <ompl/base/spaces/SE3StateSpace.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/base/StateValidityChecker.h>

#include <octomap_rrt_planner/octomap_ompl_rrt.h>

using namespace std;
using namespace Eigen;
namespace ob = ompl::base;
namespace og = ompl::geometric;

class OctomapRrtPlanner
{
  private:
    ros::NodeHandle nh_;
    ros::NodeHandle nh_private_;

    ros::Timer cmdloop_timer_;
    ros::Timer statusloop_timer_;

    OctomapOmplRrt rrt_planner_;


    void cmdloopCallback(const ros::TimerEvent& event);
    void statusloopCallback(const ros::TimerEvent& event);
    bool isStateValid(const ob::State *state);

  public:
    OctomapRrtPlanner(const ros::NodeHandle& nh, const ros::NodeHandle& nh_private);
    virtual ~ OctomapRrtPlanner();
    void planWithSimpleSetup();

};


#endif
