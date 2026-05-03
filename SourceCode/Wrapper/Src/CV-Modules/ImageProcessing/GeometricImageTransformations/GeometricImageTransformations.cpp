#include "GeometricImageTransformations.h"

using namespace cv;
using namespace std;
using namespace lvi;
using namespace lvi::mat;
using namespace lvi::array;
using namespace lvi::point;
using namespace lvi::error;
using namespace lvi::edvr;

//Not implemented on LV side, no 16US2 the rest can be converted dirctly in LabVIEW
_declspec(dllexport) void CV_GEOMETRIC_ConvertMaps(lvi::error::ErrorClusterPtr errorCluster,
    void* addressMap1, lvi::mat::MatInfo* matInfoMap1,
    void* addressMap2, lvi::mat::MatInfo* matInfoMap2,
    void* addressDstMap1, lvi::mat::MatInfo* matInfoDstMap1,
    void* addressDstMap2, lvi::mat::MatInfo* matInfoDstMap2,
    int32_t dstmap1type, LVBoolean* nninterpolation)
{
    handleError(errorCluster, [&]() -> MgErr 
    {
        Mat map1 = lvMatToCvMat(addressMap1, matInfoMap1);
        Mat map2 = lvMatToCvMat(addressMap2, matInfoMap2);
        Mat dstMap1 = lvMatToCvMat(addressDstMap1, matInfoDstMap1);
        Mat dstMap2 = lvMatToCvMat(addressDstMap2, matInfoDstMap2);

        cv::convertMaps(map1, map2, dstMap1, dstMap2, dstmap1type, static_cast<bool>(*nninterpolation));

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_GetAffineTransform(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<lvi::point::PointSGL> scr,
    lvi::array::LV_1DArrayHandle<lvi::point::PointSGL> dst,
    lvi::array::LV_2DArrayHandle<double_t> result)
{
    handleError(errorCluster, [&]() -> MgErr 
    {
        Array1D<PointSGL> srcArray(scr);
        Array1D<PointSGL> dstArray(dst);
        Array2D<double_t> resultMat(result);

        std::vector<cv::Point2f> srcPts(srcArray.size());
        std::vector<cv::Point2f> dstPts(dstArray.size());

        for (int i = 0; i < srcArray.size(); i++)
        {
            srcPts[i] = cv::Point2f(srcArray[i].x, srcArray[i].y);
            dstPts[i] = cv::Point2f(dstArray[i].x, dstArray[i].y);
        }

        cv::Mat affine = cv::getAffineTransform(srcPts, dstPts);
        return resultMat.copyFrom(affine);
    });
}

_declspec(dllexport) void CV_GEOMETRIC_GetPerspectiveTransform(lvi::error::ErrorClusterPtr errorCluster,
    lvi::array::LV_1DArrayHandle<lvi::point::PointSGL> scr,
    lvi::array::LV_1DArrayHandle<lvi::point::PointSGL> dst,
    int32_t solveMethod,
    lvi::array::LV_2DArrayHandle<double_t> result)
{
    handleError(errorCluster, [&]() -> MgErr 
    {
        Array1D<PointSGL> srcArray(scr);
        Array1D<PointSGL> dstArray(dst);
        Array2D<double_t> resultMat(result);

        std::vector<cv::Point2f> srcPts(srcArray.size());
        std::vector<cv::Point2f> dstPts(dstArray.size());

        for (int i = 0; i < srcArray.size(); i++)
        {
            srcPts[i] = cv::Point2f(srcArray[i].x, srcArray[i].y);
            dstPts[i] = cv::Point2f(dstArray[i].x, dstArray[i].y);
        }

        Mat perspective = cv::getPerspectiveTransform(srcPts, dstPts, solveMethod);
        return resultMat.copyFrom(perspective);
    });
}

_declspec(dllexport) void CV_GEOMETRIC_GetRectSubPix(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* size, lvi::point::PointSGL* center)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);

        cv::getRectSubPix(src, Size(size->x, size->y), Point2f(center->x, center->y), dst, -1);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_GetRotationMatrix2D(lvi::error::ErrorClusterPtr errorCluster,
    lvi::point::PointSGL* center, double angle,
    double scale, lvi::array::LV_2DArrayHandle<double_t> resultHandle)
{
    handleError(errorCluster, [&]() -> MgErr {
		Array2D<double_t> resultMat(resultHandle);

	    Mat rotationMatrix = cv::getRotationMatrix2D(Point2f(center->x, center->y), angle, scale);
		return resultMat.copyFrom(rotationMatrix);
     });
}


_declspec(dllexport) void CV_GEOMETRIC_InvertAffineTransform(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrcMat, lvi::mat::MatInfo* matInfoSrc,
    void* addressDstMat, lvi::mat::MatInfo* matInfoDst)
{
    handleError(errorCluster, [&]() -> MgErr 
    {
        Mat src = lvMatToCvMat(addressSrcMat, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDstMat, matInfoDst);

        cv::invertAffineTransform(src, dst);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_Remap(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    void* addressMap1, lvi::mat::MatInfo* matInfoMap1,
    void* addressMap2, lvi::mat::MatInfo* matInfoMap2,
    int32_t interpolation, int32_t borderMode,
    lvi::array::LV_1DArrayHandle<double_t> borderValue)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);
        Mat map1 = lvMatToCvMat(addressMap1, matInfoMap1);
        Mat map2 = lvMatToCvMat(addressMap2, matInfoMap2);
        Array1D<double_t> valArray(borderValue);

        cv::remap(src, dst, map1, map2, interpolation, borderMode, valArray.toScalar());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_Resize(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* size,
    lvi::point::PointSGL* factor,
    int32_t interpolation)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);

        cv::resize(src, dst, Size(size->x, size->y), factor->x, factor->y, interpolation);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_WarpAffine(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    void* addressM, lvi::mat::MatInfo* matInfoM,
    lvi::point::PointI32* size,
    int32_t flags, int32_t borderMode,
    lvi::array::LV_1DArrayHandle<double_t> borderValueHandle)
{
    handleError(errorCluster, [&]() -> MgErr {
		Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat m = lvMatToCvMat(addressM, matInfoM);
		Array1D<double_t> borderValue(borderValueHandle);

        cv::warpAffine(src, dst, m, Size(size->x, size->y), flags, borderMode, borderValue.toScalar());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_WarpPerspective(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    void* addressM, lvi::mat::MatInfo* matInfoM,
    lvi::point::PointI32* size,
    int32_t flags, int32_t borderMode,
    lvi::array::LV_1DArrayHandle<double_t> borderValue)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvDstMatToCvMat(src, addressDst, matInfoDst);
        Mat m = lvMatToCvMat(addressM, matInfoM);
        Array1D<double_t> valArray(borderValue);

        cv::warpPerspective(src, dst, m, Size(size->x, size->y), flags, borderMode, valArray.toScalar());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_GEOMETRIC_WarpPolar(lvi::error::ErrorClusterPtr errorCluster,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    lvi::point::PointI32* size, lvi::point::PointSGL* center,
    double maxRadius, int32_t flags)
{
    handleError(errorCluster, [&]() -> MgErr {
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);

        cv::warpPolar(src, dst, Size(size->x, size->y), Point2f(center->x, center->y), maxRadius, flags);

        return mgNoErr;
    });
}
