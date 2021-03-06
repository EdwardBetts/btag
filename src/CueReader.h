/*
 * This file is part of btag.
 *
 * © 2012, 2015 Fernando Tarlá Cardoso Lemos
 *
 * Refer to the LICENSE file for licensing information.
 *
 */

#ifndef CUE_READER_H
#define CUE_READER_H

#include <boost/optional.hpp>
#include <iconv.h>
#include <string>

extern "C" {
#include <libcue/libcue.h>
}

class CueReader
{
    public:
        CueReader(const std::string &filename, const std::string &encoding);
        ~CueReader();

        int number_of_tracks();

        boost::optional<std::wstring> artist_for_track(int track);
        boost::optional<std::wstring> title_for_track(int track);

        boost::optional<std::wstring> album();
        boost::optional<int> year();

    private:
        boost::optional<std::wstring> cdtext_string(Cdtext *cdt, Pti pti);

        Cd *m_cd;
        iconv_t m_iconv;
        boost::optional<std::wstring> m_artist;
};

#endif
