//////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2007-2017 musikcube team
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of the author nor the names of other contributors may
//      be used to endorse or promote products derived from this software
//      without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////////

#pragma once

#include <core/library/ILibrary.h>
#include <core/sdk/ISimpleDataProvider.h>

namespace musik { namespace core { namespace db { namespace local {

    class LocalSimpleDataProvider : public musik::core::sdk::ISimpleDataProvider {
        public:
            LocalSimpleDataProvider(musik::core::ILibraryPtr library);

            virtual ~LocalSimpleDataProvider();

            virtual musik::core::sdk::ITrackList*
                QueryTracks(
                    const char* query = "",
                    int limit = -1,
                    int offset = 0) override;

            virtual musik::core::sdk::ITrack*
                QueryTrackById(int64_t trackId) override;

            virtual musik::core::sdk::ITrack*
                QueryTrackByExternalId(const char* externalId) override;

            virtual musik::core::sdk::ITrackList*
                QueryTracksByCategory(
                    const char* categoryType,
                    int64_t selectedId,
                    const char* filter = "",
                    int limit = -1,
                    int offset = 0) override;

            virtual musik::core::sdk::IValueList*
                QueryCategory(
                    const char* type,
                    const char* filter = "") override;

            virtual musik::core::sdk::IMapList*
                QueryAlbums(const char* filter = "") override;

            virtual musik::core::sdk::IMapList* QueryAlbums(
                const char* categoryIdName,
                int64_t categoryIdValue,
                const char* filter = "") override;

            virtual uint64_t SavePlaylistWithIds(
                int64_t* trackIds,
                size_t trackIdCount,
                const char* name,
                const uint64_t playlistId = 0) override;

            virtual uint64_t SavePlaylistWithExternalIds(
                const char** externalIds,
                size_t externalIdCount,
                const char* playlistName,
                const uint64_t playlistId = 0) override;

            virtual bool RenamePlaylist(
                const uint64_t playlistId,
                const char* name) override;

            virtual bool DeletePlaylist(const uint64_t playlistId) override;

        private:
            musik::core::ILibraryPtr library;
    };

} } } }
