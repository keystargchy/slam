#ifndef __SENSOR_DATA_TYPE_H_
#define __SENSOR_DATA_TYPE_H_

namespace slam{

namespace sensor{

template<int Size>
struct LaserScan{
	LaserScan(){}
	~LaserScan(){}

	LaserScan( const LaserScan& obj ) : angle_min( obj.angle_min ),
					    angle_max( obj.angle_max ),
					    angle_increment( obj.angle_increment ),
					    scan_time( obj.scan_time ),
					    time_increment( obj.time_increment ),
					    range_min( obj.range_min ),
					    range_max( obj.range_max )
	{
		memcpy( this->ranges, obj.ranges, Size );
		memcpy( this->intensities, obj.intensities, Size );
	}

	LaserScan& operator=( const LaserScan& other )
	{
		angle_min = other.angle_min;
		angle_max = other.angle_max;
		angle_increment = other.angle_increment;
		scan_time = other.scan_time;
		time_increment = other.time_increment;
		range_min = other.range_min;
		range_max = other.range_max;

		memcpy( this->ranges, other.ranges, Size );
                memcpy( this->intensities, other.intensities, Size );
	}

	int size() const
	{
		return Size;
	}
	
	
	float angle_min;
        float angle_max;
        float angle_increment;
        float scan_time;
        float time_increment;
        float range_min;
        float range_max;
        float ranges[Size];
        float intensities[Size];
};
typedef struct LaserScan LaserScan;

}

}

#endif
