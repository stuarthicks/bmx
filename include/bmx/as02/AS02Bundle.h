/*
 * Copyright (C) 2010, British Broadcasting Corporation
 * All Rights Reserved.
 *
 * Author: Philip de Nier
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the British Broadcasting Corporation nor the names
 *       of its contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __BMX_AS02_BUNDLE_H__
#define __BMX_AS02_BUNDLE_H__


#include <string>
#include <vector>

#include <bmx/as02/AS02Shim.h>
#include <bmx/as02/AS02Manifest.h>
#include <bmx/mxf_helper/MXFFileFactory.h>



namespace bmx
{


class AS02Bundle
{
public:
    static AS02Bundle* OpenNew(std::string root_directory, bool create_root,
                               MXFFileFactory *file_factory, bool take_factory_ownership);

public:
    ~AS02Bundle();

public:
    std::string CreatePrimaryVersionFilepath(std::string *rel_uri);
    std::string CreateVersionFilepath(std::string name, std::string *rel_uri);
    std::string CreateEssenceComponentFilepath(std::string version_filename, bool is_video, uint32_t track_number,
                                               std::string *rel_uri);

    std::string CompleteFilepath(std::string rel_uri);

public:
    MXFFileFactory* GetFileFactory() const { return mFileFactory; }

    AS02Shim* GetShim() { return &mShim; }
    AS02Manifest* GetManifest() { return &mManifest; }

    void FinalizeBundle();

private:
    AS02Bundle(std::string root_filepath, MXFFileFactory *file_factory, bool take_factory_ownership);

private:
    std::string mRootFilepath;
    std::string mBundleName;
    MXFFileFactory *mFileFactory;
    bool mOwnFileFactory;

    AS02Shim mShim;
    AS02Manifest mManifest;
};


};



#endif

