#pragma once

#include "opencv2/videoio.hpp"
#include "../../../Interorp/Edvr/EdvrTypes.h"
#include "../../../Interorp/MatHandling/Mathandling.h"
#include "../../../Interorp/ErrorHandling/ErrorHandling.h"
#include "../../../Interorp/ArrayHandling/Array1D.hpp"
#include "../../../Interorp/StringHandling/StringHandling.h"

extern "C"
{

#pragma region Create / Open

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Create(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenFile(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        const char* filename, int32_t apiPreference,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenFileWithParams(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        const char* filename, int32_t apiPreference,
        lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenDevice(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t index, int32_t apiPreference,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_OpenDeviceWithParams(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t index, int32_t apiPreference,
        lvi::array::LV_1DArrayHandle<int32_t> paramsHandle,
        LVBoolean* result);

#pragma endregion Create / Open

#pragma region Read

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Read(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t* width, int32_t* height, uint32_t* imageType,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Retrieve(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t flag,
        int32_t* width, int32_t* height, uint32_t* imageType,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_CopyLastFrame(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        void* addressDst, lvi::mat::MatInfo* matInfoDst);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Grab(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        LVBoolean* result);

#pragma endregion Read

#pragma region Read Low Level

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_ReadLowLevel(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_RetrieveLowLevel(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        void* addressDst, lvi::mat::MatInfo* matInfoDst,
        int32_t flag,
        LVBoolean* result);

#pragma endregion Read Low Level

#pragma region Properties

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Get(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t propId,
        double* value);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Set(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        int32_t propId, double value,
        LVBoolean* result);

#pragma endregion Properties

#pragma region Info

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_IsOpened(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        LVBoolean* result);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_GetBackendName(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef,
        LStrHandle resultHandle);

    _declspec(dllexport) void CV_VIDEOIO_CAPTURE_Release(lvi::error::ErrorClusterPtr errorCluster,
        lvi::edvr::ReferencePtr edvrRef);

#pragma endregion Info

}
