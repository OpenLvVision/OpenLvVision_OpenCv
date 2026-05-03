#include "VideoWriter.h"

using namespace cv;
using namespace lvi;
using namespace lvi::mat;
using namespace lvi::error;
using namespace lvi::edvr;
using namespace lvi::array;
using namespace lvi::string;
using namespace lvi::point;

#pragma region Create / Open

_declspec(dllexport) void CV_VIDEOIO_WRITER_Create(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef, new cv::VideoWriter());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_Open(lvi::error::ErrorClusterPtr errorCluster, 
    lvi::edvr::ReferencePtr edvrRef,
    const char* filename, int32_t fourcc, double fps,
    lvi::point::PointI32* frameSize, LVBoolean* isColor,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        *result = writerObj->open(std::string(filename), fourcc, fps,
        Size(frameSize->x, frameSize->y), static_cast<bool>(*isColor));

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_OpenWithBackend(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    const char* filename, int32_t apiPreference,
    int32_t fourcc, double fps,
    lvi::point::PointI32* frameSize, LVBoolean* isColor,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        *result = writerObj->open(std::string(filename), apiPreference, fourcc, fps,
        Size(frameSize->x, frameSize->y), static_cast<bool>(*isColor));

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_OpenWithParams(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    const char* filename, int32_t fourcc, double fps,
    lvi::point::PointI32* frameSize,
    lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);
        Array1D<int32_t> paramsArr(paramsHandle);

        std::vector<int> params(paramsArr.data(), paramsArr.data() + paramsArr.size());
        *result = writerObj->open(std::string(filename), fourcc, fps,
        Size(frameSize->x, frameSize->y), params);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_OpenWithBackendAndParams(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    const char* filename, int32_t apiPreference,
    int32_t fourcc, double fps,
    lvi::point::PointI32* frameSize,
    lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);
        Array1D<int32_t> paramsArr(paramsHandle);

        std::vector<int> params(paramsArr.data(), paramsArr.data() + paramsArr.size());
        *result = writerObj->open(std::string(filename), apiPreference, fourcc, fps,
        Size(frameSize->x, frameSize->y), params);

        return mgNoErr;
    });
}

#pragma endregion Create / Open

#pragma region Write

_declspec(dllexport) void CV_VIDEOIO_WRITER_Write(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    void* addressSrc, lvi::mat::MatInfo* matInfoSrc)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);
        Mat src = lvMatToCvMat(addressSrc, matInfoSrc);

        writerObj->write(src);

        return mgNoErr;
    });
}

#pragma endregion Write

#pragma region Properties

_declspec(dllexport) void CV_VIDEOIO_WRITER_Get(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t propId,
    double* value)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        *value = writerObj->get(propId);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_Set(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t propId, double value,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        *result = writerObj->set(propId, value);

        return mgNoErr;
    });
}

#pragma endregion Properties

#pragma region Info

_declspec(dllexport) void CV_VIDEOIO_WRITER_IsOpened(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        *result = writerObj->isOpened();

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_GetBackendName(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    LStrHandle resultHandle)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        std::string name = writerObj->getBackendName();
        return setLvStringHandle(resultHandle, name);
    });
}

_declspec(dllexport) void CV_VIDEOIO_WRITER_Release(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<cv::VideoWriter> writerObj(edvrRef);

        writerObj->release();

        return mgNoErr;
    });
}

#pragma endregion Info