/**************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Installer Framework.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 or version 3 as published by the Free
** Software Foundation and appearing in the file LICENSE.LGPLv21 and
** LICENSE.LGPLv3 included in the packaging of this file. Please review the
** following information to ensure the GNU Lesser General Public License
** requirements will be met: https://www.gnu.org/licenses/lgpl.html and
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
**
** $QT_END_LICENSE$
**
**************************************************************************/
#ifndef LIB7Z_CREATE_H
#define LIB7Z_CREATE_H

#include "installer_global.h"

#include <Common/MyCom.h>
#include <7zip/UI/Common/Update.h>

QT_BEGIN_NAMESPACE
class QFileDevice;
class QStringList;
QT_END_NAMESPACE

namespace Lib7z
{
    enum struct QTmpFile {
        No,
        Yes
    };

    enum struct Compression {
        Non = 0,
        Fastest = 1,
        Fast = 3,
        Normal = 5,
        Maximum = 7,
        Ultra = 9
    };

    class INSTALLER_EXPORT UpdateCallback : public IUpdateCallbackUI2, public CMyUnknownImp
    {
        Q_DISABLE_COPY(UpdateCallback)

    public:
        UpdateCallback() = default;
        virtual ~UpdateCallback() {}

        MY_UNKNOWN_IMP
        INTERFACE_IUpdateCallbackUI2(;)
    };

    void INSTALLER_EXPORT createArchive(QFileDevice *archive, const QStringList &sources,
        Compression level = Compression::Normal, UpdateCallback *callback = 0);
    void INSTALLER_EXPORT createArchive(const QString &archive, const QStringList &sources,
        QTmpFile mode, Compression level = Compression::Normal, UpdateCallback *callback = 0);

} // namespace Lib7z

#endif // LIB7Z_CREATE_H
