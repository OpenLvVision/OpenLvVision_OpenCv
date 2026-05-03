#include "VideoCapture.h"

using namespace cv;
using namespace lvi;
using namespace lvi::mat;
using namespace lvi::error;
using namespace lvi::edvr;
using namespace lvi::array;
using namespace lvi::string;

#pragma region Internal

// Wrapper struct holding the VideoCapture and the last grabbed frame for two-step read.
struct CaptureData
{
    cv::VideoCapture capture;
    cv::Mat lastFrame;
};

#pragma endregion Internal

#pragma region Create / Open

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Create(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef, new CaptureData());

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenFile(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    const char* filename, int32_t apiPreference,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        *result = capObj->capture.open(std::string(filename), apiPreference);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenFileWithParams(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    const char* filename, int32_t apiPreference,
    lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);
        Array1D<int32_t> paramsArr(paramsHandle);

        std::vector<int> params(paramsArr.data(), paramsArr.data() + paramsArr.size());
        *result = capObj->capture.open(std::string(filename), apiPreference, params);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenDevice(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t index, int32_t apiPreference,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        *result = capObj->capture.open(index, apiPreference);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenDeviceWithParams(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t index, int32_t apiPreference,
    lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);
        Array1D<int32_t> paramsArr(paramsHandle);

        std::vector<int> params(paramsArr.data(), paramsArr.data() + paramsArr.size());
        *result = capObj->capture.open(index, apiPreference, params);

        return mgNoErr;
    });
}

#pragma endregion Create / Open

#pragma region Read

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Read(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t* width, int32_t* height, uint32_t* imageType,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        bool success = capObj->capture.read(capObj->lastFrame);

        if (success && !capObj->lastFrame.empty())
        {
            *width = capObj->lastFrame.cols;
            *height = capObj->lastFrame.rows;
            *imageType = static_cast<uint32_t>(cvTypeToImageType(capObj->lastFrame.type()));
        }

        *result = success;

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Retrieve(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t flag,
    int32_t* width, int32_t* height, uint32_t* imageType,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        bool success = capObj->capture.retrieve(capObj->lastFrame, flag);

        if (success && !capObj->lastFrame.empty())
        {
            *width = capObj->lastFrame.cols;
            *height = capObj->lastFrame.rows;
            *imageType = static_cast<uint32_t>(cvTypeToImageType(capObj->lastFrame.type()));
        }

        *result = success;

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_CopyLastFrame(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    void* addressDst, lvi::mat::MatInfo* matInfoDst)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);

        convertFrameToLvImage(capObj->lastFrame, dst, matInfoDst->datatype);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Grab(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        *result = capObj->capture.grab();

        return mgNoErr;
    });
}

#pragma endregion Read

#pragma region Read Low Level

//is slower i need to look into it more 
_declspec(dllexport) void CV_VIDEOIO_CAPTURE_ReadLowLevel(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);
        uchar* originalData = dst.data;

        bool success = capObj->capture.read(dst);

        if (success && !dst.empty() && dst.data != originalData)
        {
            Mat lvDst = lvMatToCvMat(addressDst, matInfoDst);
            convertFrameToLvImage(dst, lvDst, matInfoDst->datatype);
        }

        *result = success;

        return mgNoErr;
    });
}

//is slower i need to look into it more 
_declspec(dllexport) void CV_VIDEOIO_CAPTURE_RetrieveLowLevel(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    void* addressDst, lvi::mat::MatInfo* matInfoDst,
    int32_t flag,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);
        Mat dst = lvMatToCvMat(addressDst, matInfoDst);
        uchar* originalData = dst.data;

        bool success = capObj->capture.retrieve(dst, flag);

        if (success && !dst.empty() && dst.data != originalData)
        {
            Mat lvDst = lvMatToCvMat(addressDst, matInfoDst);
            convertFrameToLvImage(dst, lvDst, matInfoDst->datatype);
        }

        *result = success;

        return mgNoErr;
    });
}

#pragma endregion Read Low Level

#pragma region Properties

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Get(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t propId,
    double* value)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        *value = capObj->capture.get(propId);

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Set(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    int32_t propId, double value,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        *result = capObj->capture.set(propId, value);

        return mgNoErr;
    });
}

#pragma endregion Properties

#pragma region Info

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_IsOpened(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    LVBoolean* result)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        *result = capObj->capture.isOpened();

        return mgNoErr;
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_GetBackendName(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef,
    LStrHandle resultHandle)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        std::string name = capObj->capture.getBackendName();
        return setLvStringHandle(resultHandle, name);
    });
}

_declspec(dllexport) void CV_VIDEOIO_CAPTURE_Release(lvi::error::ErrorClusterPtr errorCluster,
    lvi::edvr::ReferencePtr edvrRef)
{
    handleError(errorCluster, [&]() -> MgErr
    {
        EdvrObject<CaptureData> capObj(edvrRef);

        capObj->capture.release();

        return mgNoErr;
    });
}

#pragma endregion Info
