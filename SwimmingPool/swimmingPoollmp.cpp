#include <iostream>
#include "swimmingPool.h"

swimmingPool::swimmingPool(double l, double w, double d, double fi, double fo, double wInPool) {
  set(l, w, d, fi, fo, wInPool);
}

void swimmingPool::set(double l, double w, double d, double fi, double fo,
double wInPool) {
  length = l;
  width = w;
  depth = d;
  waterFlowInRate = fi;
  waterFlowOutRate = fo;
  amountOfWaterInPool = wInPool;
}

void swimmingPool::addWater(double time, double fillRate) {
  amountOfWaterInPool += time * fillRate;
  if(amountOfWaterInPool > poolTotalWaterCapacity()) {
    std::cout << "Pool overflow" << std::endl;
  }
}

void swimmingPool::drainWater(double time, double drainRate) {
  amountOfWaterInPool -= time * drainRate;
  if(amountOfWaterInPool < 0) {
    amountOfWaterInPool = 0;
  }
}

double swimmingPool::poolTotalWaterCapacity() {
  return length * width * depth * GALLONS_IN_A_CUBIC_FEET;
}

int swimmingPool::timeToFillThePool() {
  return waterNeededToFillThePool() / waterFlowInRate;
}

int swimmingPool::timeToDrainThePool() {
  return amountOfWaterInPool / waterFlowOutRate;
}

double swimmingPool::waterNeededToFillThePool() {
  std::cout << poolTotalWaterCapacity() - getTotalWaterInPool() << std::endl;
  if(poolTotalWaterCapacity() <= getTotalWaterInPool()) {
    return 0;
  }
  return poolTotalWaterCapacity() - getTotalWaterInPool();
}

double swimmingPool::getLength() { return length; }
double swimmingPool::getWidth() { return width; }
double swimmingPool::getDepth() { return depth; }
double swimmingPool::getWaterFlowRateIn() { return waterFlowInRate; }
double swimmingPool::getWaterFlowRateOut() { return waterFlowOutRate; }
double swimmingPool::getTotalWaterInPool() { return amountOfWaterInPool; }

void swimmingPool::setLength(double l) { length = l; }
void swimmingPool::setWidth(double w) { width = w; }
void swimmingPool::setDepth(double d) { depth = d; }
void swimmingPool::setWaterFlowRateIn(double fi) { waterFlowInRate = fi; }
void swimmingPool::setWaterFlowRateOut(double fo) { waterFlowOutRate = fo; }
