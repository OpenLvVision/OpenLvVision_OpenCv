![OpenLvVision Header](misc/Header.png)

# OpenLvVision OpenCV

**OpenLvVision OpenCV** is a powerful LabVIEW wrapper for the **OpenCV** library. It brings advanced computer vision algorithms, linear algebra, and signal processing capabilities directly into LabVIEW, utilizing efficient **Mat** handling and polymorphic VIs.

📘 **Documentation:** For a complete reference of all functions and detailed usage, visit [openlvvision.org/docs/opencv/](https://openlvvision.org/docs/opencv/)
This library is currently in active development. Additional OpenCV modules will be included in future updates.

---

## 🔌 Dynamic MAT API

The **Mat** type is reconstructed as closely as possible using malleable and polymorphic VIs. If a function can be done in OpenCV C++, there is a high chance it will also work in the LabVIEW version.

---

## 🛠️ Functionality Overview

* 🧩**Core Functions**
    * **`ArithmeticOperations`:** `AbsDiff`, `Add`, `AddWeighted`, `ConvertScaleAbs`, `Divide`, `Exp`, `Log`, `Multiply`, `Pow`, `ScaleAdd`, `Sqrt`, `Subtract`, `Sum`
    * **`BitwiseOperations`:** `BitwiseAnd`, `BitwiseNot`, `BitwiseOr`, `BitwiseXor`
    * **`ChannelManipulation`:** `ExtractChannel`, `InsertChannel`, `LUT`, `Merge`, `MixChannels`, `Split`
    * **`Comparison`:** `CheckRange`, `Compare`, `InRange`
    * **`DataConcatenation`:** `Hconcat`, `Vconcat`
    * **`FourierTransforms`:** `Dct`, `Idct`, `Dft_Real`, `Dft_Complex`, `IDft_Real`, `IDft_Complex`, `GetOptimalDftSize`, `MulSpectrums`
    * **`GeometricOperations`:** `CartToPolar`, `PolarToCart`, `Magnitude`, `Phase`
    * **`LinearAlgebra`:** `CompleteSymm`, `Determinant`, `Eigen`, `EigenNonSymmetric`, `Gemm`, `Invert`, `MulTransposed`, `Norm`, `PatchNaNs`, `SetIdentity`, `Solve`, `SolveCubic`, `SolvePoly`
    * **`MatrixImageTransformations`:** `BorderInterpolate`, `CopyMakeBorder`, `Flip`, `FlipNd`, `PerspectiveTransform`, `Repeat`, `Rotate`, `TransformTo2D`, `TransformTo3D`, `TransformTo4D`, `Transpose`
    * **`Reduction`:** `Reduce`, `ReduceArgMax`, `ReduceArgMin`, `Trace`
    * **`SimilarityMetrics`:** `BatchDistance`, `Mahalanobis`, `PSNR`
    * **`Sort`:** `Sort`, `SortIdx`
    * **`Statistical`:** `CountNonZero`, `FindNonZero`, `HasNonZero`, `Max`, `Min`, `Mean`, `MeanStdDev`, `MinMaxIdx`, `MinMaxLoc`, `Normalize`
    * **`LDA` (Class & Funcs):**
        * `Create`, `Compute`, `Load/Save`, `Reconstruct`, `Project`, `SubspaceProject`, `SubspaceReconstruct`
    * **`PCA` (Class & Funcs):**
        * `Create`, `Compute`, `Read/Write`, `Project`, `BackProject`, `PCACompute`, `PCABackProject`, `PCAProject`
    * **`SVD` (Class & Funcs):**
        * `Create`, `Decompose`, `BackSubst`, `Read`, `SVBackSubst`, `SVDecomp`, `SVD_Compute`, `SVD_SolveZ`
    * **`RNG` (Class & Funcs):**
        * `Create`, `Fill`, `Gaussian`, `Next`, `Read/Write State`, `Uniform` (Int/Float/Double), `Randn`, `RandShuffle`, `Randu`, `WriteRngSeed`

* 🧠**Deep Neural Network (DNN)**
    * **`Environment`:** `NmsBoxes`, `NmsBoxesRotated`, `GetAvailableBackends`, `GetAvailableTargets` *(x64 includes OpenVINO & CUDA backends)*
    * **`Net` (Class):**
        * `Create`, `ReadNet`, `Forward`, `SetInput`, `DumpToFile`, `DumpToPbtxt`
        * **Configure:** `Connect`, `Backend/Target`, `Fusion`, `Winograd`, `Halide`, `Shapes/Names`, `Outputs`
        * **Layers:** `Id`, `Names`, `Count`, `Types`, `Shapes`, `Unconnected`
        * **Performance:** `FLOPS`, `Memory`, `PerfProfile`
    * **`Blob` (Class):**
        * `Create`, `BlobFromImage`, `BlobFromImages`, `ReadInfo`, `ReadData`

* 🖼️**Image Processing**
    * **`ImageFiltering`:** `Bilateralfilter`, `Blur`, `BoxFilter`, `Filter2d`, `GaussianBlur`, `GetDerivKernels`, `GetGaborKernel`, `GetGaussianKernel`, `Laplacian`, `MedianBlur`, `Dilate`, `Erode`, `GetStructuringElement`, `MorphologyDefaultBorderValue`, `MorphologyEx`, `PyrDown`, `PyrMeanShiftFiltering`, `PyrUp`, `Scharr`, `SepFilter2D`, `Sobel`, `SpatialGradient`, `SqrBoxFilter`
    * **`ObjectDetection`:** `MatchTemplate`

* 💻**System**
    * **`Hardware & Build`:** `CheckHardware`, `GetBuildInfos`, `GetNumThreads`, `GetVersion`, `SetNumThrea

* 🎥**Video I/O**
   * **`VideoCapture` (Class):**
     `Create`, `Dispose`, `Get`, `GetBackendName`, `Grab`, `IsOpened`, `OpenFile`, `OpenDevice` , `Read` , `Release` , `Retrive` , `Set`
   * **`VideoWriter` (Class):**
     `Create`, `Dispose`, `Get`, `GetBackendName`, `Open` , `Release` , `Retrive` , `Set`, `Write`

---

## 📥 Installation

1.  **Online:** Install the **OpenLvVision** package directly via [VI Package Manager (VIPM)](https://www.vipm.io/publisher/openlvvision/).
2.  **Offline:** For offline installation, visit the [Installation Guide](https://openlvvision.org/docs/installation/openlvvision/).

### 🖥️ System Requirements
* **LabVIEW:** 2020 or newer (including the Community Edition)
* **OS:** Windows operating system
* **Dependencies:** Vision Common Resources (license free)

---

## ⚖️ Third Party Copyrights

* Copyright (c) 2010-2013, Advanced Micro Devices, Inc., all rights reserved.
* Copyright (c) 2020 BlackBerry Limited.
* Copyright (c) 2008-2009 Davide Barbieri @ University of Rome Tor Vergata.
* Copyright (c) 2010-2011 D. E. Shaw Research.
* Copyright (c) 2005-2014 Daniel James.
* Copyright (c) 2007, 2009 Free Software Foundation, Inc.
* Copyright (c) 2019-2020 FUJITSU LIMITED.
* Copyright (c) 2005-2016 Google Inc.
* Copyright (c) 2000-2026, Intel Corporation and its affiliates, all rights reserved.
* Copyright (c) 2008-2016, Itseez Inc., all rights reserved.
* Copyright (c) 1995-2017 Jean-loup Gailly and Mark Adler.
* Copyright (c) 2023-2026, John Medland, all rights reserved.
* Copyright (c) 1994-2008 John E. Stone.
* Copyright (c) 2013 King Abdullah University of Science and Technology.
* Copyright (c) 2000-2020 Kitware, Inc. and Contributors.
* Copyright (c) 2015 Matei David, Ontario Institute for Cancer Research.
* Copyright (c) Meta Platforms, Inc. and affiliates.
* Copyright (c) Microsoft Corporation.
* Copyright (c) 2007 MITSUNARI Shigeo.
* Copyright (c) 2009-2011 Mutsuo Saito, Makoto Matsumoto, Hiroshima University, and University of Tokyo.
* Copyright (c) 2010-2021 Naoki Shibata and contributors.
* Copyright (c) 2000–2026, National Instruments Corporation, all rights reserved.
* Copyright (c) 2015-2017 Norbert Juffa.
* Copyright (c) 2009-2026, NVIDIA Corporation & affiliates, all rights reserved.
* Copyright (c) 2015-2023, OpenCV Foundation, all rights reserved.
* Copyright (c) 2016 OpenAI.
* Copyright (c) 2004-2016 Portable Hardware Locality (hwloc) contributors 
* Copyright (c) 2006-2016 R Oudkerk, david decotigny.
* Copyright (c) 2007-2009 Regents of the University of California.
* Copyright (c) 2019-2022, Shenzhen Institute of Artificial Intelligence and Robotics for Society, all rights reserved.
* Copyright (c) 2022-2023, Southern University of Science And Technology, all rights reserved.
* Copyright (c) 2015 THL A29 Limited, a Tencent company, and Milo Yip.
* Copyright (c) 2012 The Science and Technology Facilities Council (STFC).
* Copyright (c) 2007-2021 by the Sphinx team.
* Copyright (c) 2011-2014, The OpenBLAS Project, all rights reserved.
* Copyright (c) 2016 Tibbo Technology Inc, Vladimir Gladkov, Doxyrest maintainers.
* Copyright (c) 1997-2012 University of Cambridge.
* Copyright (c) 2003-2012 University of Illinois at Urbana-Champaign.
* Copyright (c) 2010 The University of Tennessee.
* Copyright (c) 2012-present Victor Zverovich.
* Copyright (c) 2016-2021 Viktor Kirilov.
* Copyright (c) 2009-2011, Willow Garage Inc., all rights reserved.
* Copyright (c) 2019-2023, Xperience AI, all rights reserved.
* Copyright (c) 2011-2013 Yann Collet.
* Copyright (c) 2009-2012 Zoltan Herczeg.
* Copyright (c) 2001 Fabrice Bellard.

*Third party copyrights are property of their respective owners.*