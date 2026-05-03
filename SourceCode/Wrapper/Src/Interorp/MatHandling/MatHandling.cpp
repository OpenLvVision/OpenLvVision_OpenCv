#include "MatHandling.h"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace lvi::mat;


Mat lvi::mat::lvMatToCvMat(void* address, MatInfo* matInfo)
{
    if (matInfo->null == 1)
    {
        //return empty matrix		
        return Mat();
    }

    int32_t height = matInfo->height;
    int32_t width = matInfo->width;
    int32_t lineWidth = matInfo->lineWidth;

    switch (matInfo->datatype)
    {
        // Use enum class scope
    case DataType::Array1dU8:
        return Mat(height, width, CV_8UC1, reinterpret_cast<uint8_t*>(address));
    case DataType::Array1dI8:
        return Mat(height, width, CV_8SC1, reinterpret_cast<int8_t*>(address));
    case DataType::Array1dU16:
        return Mat(height, width, CV_16UC1, reinterpret_cast<uint16_t*>(address));
    case DataType::Array1dI16:
        return Mat(height, width, CV_16SC1, reinterpret_cast<int16_t*>(address));
    case DataType::Array1dU32_Color:
        return Mat(height, width, CV_8UC4, reinterpret_cast<uint32_t*>(address));
    case DataType::Array1dI32:
        return Mat(height, width, CV_32SC1, reinterpret_cast<int32_t*>(address));
    case DataType::Array1dU64_Color:
        return Mat(height, width, CV_16UC4, reinterpret_cast<uint64_t*>(address));
    case DataType::Array1dSgl:
        return Mat(height, width, CV_32FC1, reinterpret_cast<float*>(address));
    case DataType::Array1dComplexSgl:
        return Mat(height, width, CV_32FC2, reinterpret_cast<float*>(address));
    case DataType::Array1dDbl:
        return Mat(height, width, CV_64FC1, reinterpret_cast<double*>(address));
    case DataType::Array1dComplexDbl:
        return Mat(height, width, CV_64FC2, reinterpret_cast<double*>(address));
    case DataType::Array2dU8:
        return Mat(height, width, CV_8UC1, reinterpret_cast<uint8_t*>(address));
    case DataType::Array2dI8:
        return Mat(height, width, CV_8SC1, reinterpret_cast<int8_t*>(address));
    case DataType::Array2dU16:
        return Mat(height, width, CV_16UC1, reinterpret_cast<uint16_t*>(address));
    case DataType::Array2dI16:
        return Mat(height, width, CV_16SC1, reinterpret_cast<int16_t*>(address));
    case DataType::Array2dU32_Color:
        return Mat(height, width, CV_8UC4, reinterpret_cast<uint32_t*>(address));
    case DataType::Array2dI32:
        return Mat(height, width, CV_32SC1, reinterpret_cast<int32_t*>(address));
    case DataType::Array2dU64_Color:
        return Mat(height, width, CV_16UC4, reinterpret_cast<uint64_t*>(address));
    case DataType::Array2dSgl:
        return Mat(height, width, CV_32FC1, reinterpret_cast<float*>(address));
    case DataType::Array2dComplexSgl:
        return Mat(height, width, CV_32FC2, reinterpret_cast<float*>(address));
    case DataType::Array2dDbl:
        return Mat(height, width, CV_64FC1, reinterpret_cast<double*>(address));
    case DataType::Array2dComplexDbl:
        return Mat(height, width, CV_64FC2, reinterpret_cast<double*>(address));
    case DataType::ImageMonoU8:
        return Mat(height, width, CV_8UC1, reinterpret_cast<uint8_t*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::ImageMonoU16:
        return Mat(height, width, CV_16UC1, reinterpret_cast<uint16_t*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::ImageMonoI16:
        return Mat(height, width, CV_16SC1, reinterpret_cast<int16_t*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::ImageMonoSgl:
        return Mat(height, width, CV_32FC1, reinterpret_cast<float*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::ImageColorU32:
        return Mat(height, width, CV_8UC4, reinterpret_cast<uint8_t*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::ImageColorU64:
        return Mat(height, width, CV_16UC4, reinterpret_cast<uint16_t*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::ImageComplexSgl:
        return Mat(height, width, CV_32FC2, reinterpret_cast<float*>(*static_cast<uint64_t*>(address)), lineWidth);
    case DataType::Array1d_2dPointI32:
        return Mat(height, width, CV_32SC2, reinterpret_cast<int32_t*>(address));
    case DataType::Array1d_2dPointSGL:
        return Mat(height, width, CV_32FC2, reinterpret_cast<float*>(address));
    case DataType::Array1d_2dPointDBL:
        return Mat(height, width, CV_64FC2, reinterpret_cast<double*>(address));
    case DataType::Array1d_3dPointI32:
        return Mat(height, width, CV_32SC3, reinterpret_cast<int32_t*>(address));
    case DataType::Array1d_3dPointSGL:
        return Mat(height, width, CV_32FC3, reinterpret_cast<float*>(address));
    case DataType::Array1d_3dPointDBL:
        return Mat(height, width, CV_64FC3, reinterpret_cast<double*>(address));
    case DataType::Array1d_4dPointI32:
        return Mat(height, width, CV_32SC4, reinterpret_cast<int32_t*>(address));
    case DataType::Array1d_4dPointSGL:
        return Mat(height, width, CV_32FC4, reinterpret_cast<float*>(address));
    case DataType::Array1d_4dPointDBL:
        return Mat(height, width, CV_64FC4, reinterpret_cast<double*>(address));
    default:
        throw std::runtime_error("Format not supported in lvMatToCvMat");
    }
}

cv::Mat lvi::mat::lvNchwMatToCvNchwMat(void* address, NchwMatInfo* matInfo)
{
    if (matInfo->null == 1)
    {       	
        throw std::runtime_error("NchwMat is null");
    }

	int sizes[] = {matInfo->dimensions, matInfo->channels, matInfo->height, matInfo->width};

    switch (matInfo->datatype)
    {
	case lvi::mat::DataType::ArrayNchwU8:
        return Mat(4, sizes, CV_8U, reinterpret_cast<uint8_t*>(address));
    case lvi::mat::DataType::ArrayNchwI8:
        return Mat(4, sizes, CV_8S, reinterpret_cast<int8_t*>(address));
    case lvi::mat::DataType::ArrayNchwU16:
        return Mat(4, sizes, CV_16U, reinterpret_cast<uint16_t*>(address));
    case lvi::mat::DataType::ArrayNchwI16:
        return Mat(4, sizes, CV_16S, reinterpret_cast<int16_t*>(address));
    case lvi::mat::DataType::ArrayNchwU32_Color:
        return Mat(4, sizes, CV_8SC4, reinterpret_cast<uint32_t*>(address));
    case lvi::mat::DataType::ArrayNchwI32:
        return Mat(4, sizes, CV_32S, reinterpret_cast<int32_t*>(address));
    case lvi::mat::DataType::ArrayNchwU64_Color:
        return Mat(4, sizes, CV_16SC4, reinterpret_cast<uint32_t*>(address));
    case lvi::mat::DataType::ArrayNchwSgl:
        return Mat(4, sizes, CV_32F, reinterpret_cast<float*>(address));
    case lvi::mat::DataType::ArrayNchwDbl:
        return Mat(4, sizes, CV_64F, reinterpret_cast<double*>(address));
    case lvi::mat::DataType::ArrayNchwComplexSgl:
        return Mat(4, sizes, CV_32FC1, reinterpret_cast<float*>(address));
    case lvi::mat::DataType::ArrayNchwComplexDbl:
        return Mat(4, sizes, CV_64FC1, reinterpret_cast<double*>(address));
    default:
        throw std::runtime_error("Format not supported in lvMatToCvMat");
    }
}

Mat lvi::mat::lvDstMatToCvMat(Mat src, void* addressDst, MatInfo* matInfoDst)
{
    //NULL not possible in Labview
    if (matInfoDst->null == 1)
    {
        //point to source
        return src;
    }
    else
    {
        //point to destination image
        return lvMatToCvMat(addressDst, matInfoDst);
    }
}

ImageType lvi::mat::cvTypeToImageType(int cvType)
{
    switch (cvType)
    {
    case CV_8UC1:  return ImageType::MonoU8;
    case CV_16UC1: return ImageType::MonoU16;
    case CV_16SC1: return ImageType::MonoI16;
    case CV_32FC1: return ImageType::MonoSgl;
    case CV_8UC3:  return ImageType::ColorU32;
    case CV_8UC4:  return ImageType::ColorU32;
    case CV_16UC3: return ImageType::ColorU64;
    case CV_16UC4: return ImageType::ColorU64;
    case CV_32FC2: return ImageType::ComplexSgl;
    default:       return ImageType::ColorU32;
    }
}

void lvi::mat::getImageTypeProperties(DataType dt, int& channels, int& depth)
{
    switch (dt)
    {
    case DataType::ImageMonoU8:     channels = 1; depth = CV_8U;  break;
    case DataType::ImageMonoU16:    channels = 1; depth = CV_16U; break;
    case DataType::ImageMonoI16:    channels = 1; depth = CV_16S; break;
    case DataType::ImageMonoSgl:    channels = 1; depth = CV_32F; break;
    case DataType::ImageColorU32:   channels = 4; depth = CV_8U;  break;
    case DataType::ImageColorU64:   channels = 4; depth = CV_16U; break;
    case DataType::ImageComplexSgl: channels = 2; depth = CV_32F; break;
    default: throw std::runtime_error("Unsupported image DataType");
    }
}

int lvi::mat::getCvtColorCode(int srcChannels, int dstChannels)
{
    if (srcChannels == dstChannels) return -1;

    if (srcChannels == 3 && dstChannels == 1) return cv::COLOR_BGR2GRAY;
    if (srcChannels == 3 && dstChannels == 4) return cv::COLOR_BGR2BGRA;
    if (srcChannels == 4 && dstChannels == 1) return cv::COLOR_BGRA2GRAY;
    if (srcChannels == 4 && dstChannels == 3) return cv::COLOR_BGRA2BGR;
    if (srcChannels == 1 && dstChannels == 3) return cv::COLOR_GRAY2BGR;
    if (srcChannels == 1 && dstChannels == 4) return cv::COLOR_GRAY2BGRA;

    throw std::runtime_error("Unsupported color conversion");
}

void lvi::mat::convertFrameToLvImage(const cv::Mat& src, cv::Mat& dst, DataType targetType)
{
    int dstChannels, dstDepth;
    getImageTypeProperties(targetType, dstChannels, dstDepth);

    const cv::Mat* current = &src;
    cv::Mat temp;

    // Step 1: Color conversion if channel count differs
    int code = getCvtColorCode(src.channels(), dstChannels);
    if (code >= 0)
    {
        cv::cvtColor(*current, temp, code);
        current = &temp;
    }

    // Step 2: Depth conversion + copy into LV buffer
    if (current->depth() != dstDepth)
    {
        cv::Mat converted;
        current->convertTo(converted, CV_MAKETYPE(dstDepth, dstChannels));
        converted.copyTo(dst);
    }
    else
    {
        current->copyTo(dst);
    }
}