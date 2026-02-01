#include "ImageFiltering.h"

using namespace cv;
using namespace std;
using namespace lvi;
using namespace lvi::mat;
using namespace lvi::array;
using namespace lvi::point;
using namespace lvi::error;
using namespace lvi::edvr;

_declspec(dllexport) void CV_FILTER_BilateralFilter(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    int32_t d, double sigmaColor, double sigmaSpace, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace, borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_Blur(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    lvi::point::PointI32* kSize,
    lvi::point::PointI32* anchor, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

		cv::blur(src, dst, Size(kSize->x, kSize->y), Point(anchor->x, anchor->y), borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_BoxFilter(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    lvi::point::PointI32* kSize,
    lvi::point::PointI32* anchor, 
    LVBoolean* normalize, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);


        cv::boxFilter(src, dst, -1, Size(kSize->x, kSize->y), Point(anchor->x, anchor->y), static_cast<bool>(*normalize), borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_Dilate(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    void* addressKernel, MatInfo* matInfoKernel,
    lvi::point::PointI32* anchor, int32_t iterations,
    int32_t borderType, lvi::array::LV_1DArrayHandle<double_t> borderValue)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat kernel = lvMatToCvMat(addressKernel, matInfoKernel);
        Array1D<double_t> valArray(borderValue);

        cv::dilate(src, dst, kernel, Point(anchor->x, anchor->y), iterations, borderType, valArray.toScalar());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_Erode(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    void* addressKernel, MatInfo* matInfoKernel,
    lvi::point::PointI32* anchor, int32_t iterations,
    int32_t borderType, lvi::array::LV_1DArrayHandle<double_t> borderValue)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat kernel = lvMatToCvMat(addressKernel, matInfoKernel);
        Array1D<double_t> valArray(borderValue);

        cv::erode(src, dst, kernel, Point(anchor->x, anchor->y), iterations, borderType, valArray.toScalar());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_Filter2D(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    void* addressKernel, MatInfo* matInfoKernel,
    lvi::point::PointI32* anchor, 
    double delta, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat kernel = lvMatToCvMat(addressKernel, matInfoKernel);

        cv::filter2D(src, dst, -1, kernel, Point(anchor->x, anchor->y), delta, 4);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_GaussianBlur(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    lvi::point::PointI32* kSize,
    double sigmaX, double sigmaY,
    int32_t borderType, int32_t AlgorithmHint)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

		cv::GaussianBlur(src, dst, Size(kSize->x, kSize->y), sigmaX, sigmaY, borderType, static_cast<cv::AlgorithmHint>(AlgorithmHint));

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_GetDerivKernel(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<double_t> kxHandle,
    lvi::array::LV_1DArrayHandle<double_t> kyHandle,
    int32_t dx, int32_t dy, 
    int32_t ksize, LVBoolean* normalize)
{
    handleError(errorCluster, [&]() -> MgErr {
        Array1D<double_t> kx(kxHandle);
        Array1D<double_t> ky(kyHandle);

        Mat tempKx, tempKy;
        cv::getDerivKernels(tempKx, tempKy, dx, dy, ksize, static_cast<bool>(*normalize), CV_64F);

		kx.copyFrom(tempKx);
		ky.copyFrom(tempKy);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_GetGaborKernel(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_2DArrayHandle<double_t> dstHandle,
    lvi::point::PointI32* kSize,
    double sigma, double theta, 
    double lambd, double gamma, 
    double psi)
{
    handleError(errorCluster, [&]() -> MgErr {
        Array2D<double_t> dst(dstHandle);
        Mat kernel;

        kernel = cv::getGaborKernel(Size(kSize->x, kSize->y), sigma, theta, lambd, gamma, psi, CV_64F);
        return dst.copyFrom(kernel);;
    });
}

_declspec(dllexport) void CV_FILTER_GetGaussianKernel(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<double_t> dstHandle,
    int32_t kSize,double sigma)
{
    handleError(errorCluster, [&]() -> MgErr {
        Array1D<double_t> dst(dstHandle);
        Mat kernel;

        kernel = cv::getGaussianKernel(kSize, sigma, CV_64F);
        return dst.copyFrom(kernel);
    });
}

_declspec(dllexport) void CV_FILTER_GetStructuringElement(lvi::error::ErrorClusterPtr errorCluster,
    int32_t shape,
    lvi::point::PointI32* kSize,
    lvi::point::PointI32* anchor,
    lvi::array::LV_2DArrayHandle<uint8_t> dstHandle)
{
    handleError(errorCluster, [&]() -> MgErr {
        Array2D<uint8_t> dst(dstHandle);
        Mat structuringElement;

        structuringElement = cv::getStructuringElement(shape, Size(kSize->x, kSize->y), Point(anchor->x, anchor->y));
        return dst.copyFrom(structuringElement);
    });
}

_declspec(dllexport) void CV_FILTER_Laplacian(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    int32_t ksize, double scale,
    double delta, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::Laplacian(src, dst, -1, ksize,scale,delta, borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_MedianBlur(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    int32_t ksize)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::medianBlur(src, dst, ksize);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_MorphologyDefaultBorderValue(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<double_t> dstHandle)
{
    handleError(errorCluster, [&]() -> MgErr {
        Array1D<double_t> dst(dstHandle);
        Scalar borderValue; 

        borderValue = cv::morphologyDefaultBorderValue();
        
		return dst.copyFrom(borderValue);
    });
}

_declspec(dllexport) void CV_FILTER_MorphologyEx(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    int32_t op,
    void* addressKernel, MatInfo* matInfoKernel,
    lvi::point::PointI32* anchor,
    int32_t iterations, int32_t borderType,
    lvi::array::LV_1DArrayHandle<double_t> borderValue)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat kernel = lvMatToCvMat(addressKernel, matInfoKernel);
        Array1D<double_t> valArray(borderValue);

        cv::morphologyEx(src, dst, op, kernel, Point(anchor->x, anchor->y), iterations, borderType, valArray.toScalar());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_PyrDown(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    lvi::point::PointI32* dstSize,
    int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::pyrDown(src, dst, Size(dstSize->x, dstSize->y), borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_PyrMeanShiftFiltering(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    double sp, double sr,
    int32_t maxLevel, int32_t termCritType, 
    int32_t termCritMaxCount, double termCritEpsilon)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat src3, dst3;

        TermCriteria tc(termCritType, termCritMaxCount, termCritEpsilon);

        cv::cvtColor(src, src3, COLOR_BGRA2BGR);
        cv::pyrMeanShiftFiltering(src3, dst3, sp, sr, maxLevel, tc);
        cv::cvtColor(dst3, dst, COLOR_BGR2BGRA);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_PyrUp(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, MatInfo* matInfoSrc,
    void* addressDst, MatInfo* matInfoDst,
    lvi::point::PointI32* dstSize,
    int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::pyrUp(src, dst, Size(dstSize->x, dstSize->y), borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_Scharr(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* derivative,
    double scale, double delta,
    int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::Scharr(src, dst,-1,derivative->x, derivative->y, scale, delta, borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_SepFilter2D(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    void* addressKernelX, lvi::mat::MatInfo* matInfoKernelX,
    void* addressKernelY, lvi::mat::MatInfo* matInfoKernelY,
    lvi::point::PointI32* anchor,
    double delta, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat kernelX = lvMatToCvMat(addressKernelX, matInfoKernelX);
        Mat kernelY = lvMatToCvMat(addressKernelY, matInfoKernelY);

        cv::sepFilter2D(src, dst, -1, kernelX, kernelY, Point(anchor->x, anchor->y), delta, borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_Sobel(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* derivative,
    int32_t ksize, double scale,
    double delta, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);

        cv::Sobel(src, dst, -1, derivative->x, derivative->y, ksize, scale, delta, borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_SpatialGradient(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDx, lvi::mat::MatInfo* matInfoDx,
    void* addressDy, lvi::mat::MatInfo* matInfoDy,
    int32_t ksize, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dx = lvMatToCvMat(addressDx, matInfoDx);
        Mat dy = lvMatToCvMat(addressDy, matInfoDy);

        cv::spatialGradient(src, dx,dy, ksize,borderType);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_FILTER_SqrBoxFilter(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* kSize,
    lvi::point::PointI32* anchor,
    LVBoolean* normalize, int32_t borderType)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);

        cv::sqrBoxFilter(src, dst, dst.type(), Size(kSize->x, kSize->y), Point(anchor->x, anchor->y), static_cast<bool>(*normalize), borderType);

        return mgNoErr;
    });
}


_declspec(dllexport) void CV_FILTER_StackBlur(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* kSize)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);

        cv::stackBlur(src, dst, Size(kSize->x, kSize->y));

        return mgNoErr;
    });
}