#pragma once

#include "opencv2/imgproc.hpp"
#include "../../../Interorp/MatHandling/Mathandling.h"
#include "../../../Interorp/ErrorHandling/ErrorHandling.h"
#include "../../../Interorp/ArrayHandling/Array1D.hpp"
#include "../../../Interorp/ArrayHandling/Array2D.hpp"
#include "../../../Interorp/Points.hpp"

using namespace std;
using namespace cv;

extern "C"
{
    _declspec(dllexport) void CV_FILTER_BilateralFilter(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        int32_t d, double sigmaColor, double sigmaSpace, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_Blur(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* kSize,
        lvi::point::PointI32* anchor, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_BoxFilter(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* kSize,
        lvi::point::PointI32* anchor, 
        LVBoolean* normalize, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_Dilate(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        void* addressKernel, lvi::mat::MatInfo* matInfoKernel,
        lvi::point::PointI32* anchor, int32_t iterations,
        int32_t borderType, lvi::array::LV_1DArrayHandle<double_t> borderValue);

    _declspec(dllexport) void CV_FILTER_Erode(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        void* addressKernel, lvi::mat::MatInfo* matInfoKernel,
        lvi::point::PointI32* anchor, int32_t iterations,
        int32_t borderType, lvi::array::LV_1DArrayHandle<double_t> borderValue);

    _declspec(dllexport) void CV_FILTER_Filter2D(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        void* addressKernel, lvi::mat::MatInfo* matInfoKernel,
        lvi::point::PointI32* anchor,
        double delta, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_GaussianBlur(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* kSize,
        double sigmaX, double sigmaY,
        int32_t borderType, int32_t AlgorithmHint);

    _declspec(dllexport) void CV_FILTER_GetDerivKernel(lvi::error::ErrorClusterPtr errorCluster,
        lvi::array::LV_1DArrayHandle<double_t> kxHandle,
        lvi::array::LV_1DArrayHandle<double_t> kyHandle,
        int32_t dx, int32_t dy, 
        int32_t ksize, LVBoolean* normalize);

    _declspec(dllexport) void CV_FILTER_GetGaborKernel(lvi::error::ErrorClusterPtr errorCluster,
        lvi::array::LV_2DArrayHandle<double_t> dstHandle,
        lvi::point::PointI32* kSize,
        double sigma, double theta,
        double lambd, double gamma,
        double psi);

    _declspec(dllexport) void CV_FILTER_GetGaussianKernel(lvi::error::ErrorClusterPtr errorCluster,
        lvi::array::LV_1DArrayHandle<double_t> dstHandle,
        int32_t kSize, double sigma);

   _declspec(dllexport) void CV_FILTER_GetStructuringElement(lvi::error::ErrorClusterPtr errorCluster,
       int32_t shape,
       lvi::point::PointI32* kSize,
       lvi::point::PointI32* anchor,
       lvi::array::LV_2DArrayHandle<uint8_t> dstHandle);

    _declspec(dllexport) void CV_FILTER_Laplacian(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        int32_t ksize, double scale,
        double delta, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_MedianBlur(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        int32_t ksize);

    _declspec(dllexport) void CV_FILTER_MorphologyDefaultBorderValue(lvi::error::ErrorClusterPtr errorCluster,
        lvi::array::LV_1DArrayHandle<double_t> dstHandle);

    _declspec(dllexport) void CV_FILTER_MorphologyEx(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        int32_t op,
        void* addressKernel, lvi::mat::MatInfo* matInfoKernel,
        lvi::point::PointI32* anchor, 
        int32_t iterations, int32_t borderType, 
        lvi::array::LV_1DArrayHandle<double_t> borderValue);

     _declspec(dllexport) void CV_FILTER_PyrDown(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* dstSize,
        int32_t borderType);

     _declspec(dllexport) void CV_FILTER_PyrMeanShiftFiltering(lvi::error::ErrorClusterPtr errorCluster,
         void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
         void* addressDst, lvi::mat::MatInfo* matInfoDst,
         double sp, double sr,
         int32_t maxLevel, int32_t termCritType,
         int32_t termCritMaxCount, double termCritEpsilon);

    _declspec(dllexport) void CV_FILTER_PyrUp(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* dstSize,
        int32_t borderType);

    _declspec(dllexport) void CV_FILTER_Scharr(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* derivative,
        double scale, double delta,
        int32_t borderType);

    _declspec(dllexport) void CV_FILTER_SepFilter2D(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        void* addressKernelX, lvi::mat::MatInfo* matInfoKernelX,
        void* addressKernelY, lvi::mat::MatInfo* matInfoKernelY,
        lvi::point::PointI32* anchor,
        double delta, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_Sobel(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* derivative,
        int32_t ksize, double scale,
        double delta, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_SpatialGradient(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDx, lvi::mat::MatInfo* matInfoDx,
        void* addressDy, lvi::mat::MatInfo* matInfoDy,
        int32_t ksize, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_SqrBoxFilter(lvi::error::ErrorClusterPtr errorCluster,
        void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* kSize,
        lvi::point::PointI32* anchor, 
        LVBoolean* normalize, int32_t borderType);

    _declspec(dllexport) void CV_FILTER_StackBlur(lvi::error::ErrorClusterPtr errorCluster,
       void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
       void* addressDst, lvi::mat::MatInfo* matInfoDst,
        lvi::point::PointI32* kSize);

}