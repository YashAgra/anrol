// Generated by gencpp from file rosserial_msgs/RequestServiceInfoResponse.msg
// DO NOT EDIT!


#ifndef ROSSERIAL_MSGS_MESSAGE_REQUESTSERVICEINFORESPONSE_H
#define ROSSERIAL_MSGS_MESSAGE_REQUESTSERVICEINFORESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosserial_msgs
{
template <class ContainerAllocator>
struct RequestServiceInfoResponse_
{
  typedef RequestServiceInfoResponse_<ContainerAllocator> Type;

  RequestServiceInfoResponse_()
    : service_md5()
    , request_md5()
    , response_md5()  {
    }
  RequestServiceInfoResponse_(const ContainerAllocator& _alloc)
    : service_md5(_alloc)
    , request_md5(_alloc)
    , response_md5(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _service_md5_type;
  _service_md5_type service_md5;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _request_md5_type;
  _request_md5_type request_md5;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _response_md5_type;
  _response_md5_type response_md5;





  typedef boost::shared_ptr< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> const> ConstPtr;

}; // struct RequestServiceInfoResponse_

typedef ::rosserial_msgs::RequestServiceInfoResponse_<std::allocator<void> > RequestServiceInfoResponse;

typedef boost::shared_ptr< ::rosserial_msgs::RequestServiceInfoResponse > RequestServiceInfoResponsePtr;
typedef boost::shared_ptr< ::rosserial_msgs::RequestServiceInfoResponse const> RequestServiceInfoResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator1> & lhs, const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator2> & rhs)
{
  return lhs.service_md5 == rhs.service_md5 &&
    lhs.request_md5 == rhs.request_md5 &&
    lhs.response_md5 == rhs.response_md5;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator1> & lhs, const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rosserial_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c3d6dd25b909596479fbbc6559fa6874";
  }

  static const char* value(const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc3d6dd25b9095964ULL;
  static const uint64_t static_value2 = 0x79fbbc6559fa6874ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosserial_msgs/RequestServiceInfoResponse";
  }

  static const char* value(const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string service_md5\n"
"string request_md5\n"
"string response_md5\n"
"\n"
;
  }

  static const char* value(const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.service_md5);
      stream.next(m.request_md5);
      stream.next(m.response_md5);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RequestServiceInfoResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosserial_msgs::RequestServiceInfoResponse_<ContainerAllocator>& v)
  {
    s << indent << "service_md5: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.service_md5);
    s << indent << "request_md5: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.request_md5);
    s << indent << "response_md5: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.response_md5);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSSERIAL_MSGS_MESSAGE_REQUESTSERVICEINFORESPONSE_H
