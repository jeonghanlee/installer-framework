/**************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Installer Framework.
**
** $QT_BEGIN_LICENSE:LGPL21$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
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
** $QT_END_LICENSE$
**
**************************************************************************/
#ifndef TESTREPOSITORY_H
#define TESTREPOSITORY_H

#include "downloadfiletask.h"
#include "job.h"
#include "repository.h"

#include <QFutureWatcher>
#include <QTimer>

namespace QInstaller {

class PackageManagerCore;

class INSTALLER_EXPORT TestRepository : public Job
{
    Q_OBJECT
    Q_DISABLE_COPY(TestRepository)

public:
    explicit TestRepository(PackageManagerCore *parent = 0);
    ~TestRepository();

    Repository repository() const;
    void setRepository(const Repository &repository);

private slots:
    void doStart();
    void doCancel();

    void onTimeout();
    void downloadCompleted();

private:
    void reset();

private:
    PackageManagerCore *m_core;

    QTimer m_timer;
    Repository m_repository;
    QFutureWatcher<FileTaskResult> m_xmlTask;
};

} // namespace QInstaller

#endif  // TESTREPOSITORY_H
