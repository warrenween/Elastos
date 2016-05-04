/*
 * Copyright (C) 2006, 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.android.internal.telephony.uicc;

using Elastos::Droid::Telephony::IRlog;

using Elastos::Droid::Internal::Telephony::ICommandsInterface;

/**
 * {@hide}
 * This class should be used to access files in CSIM ADF
 */
public class CsimFileHandler extends IccFileHandler implements IccConstants {
    static const String LOG_TAG = "CsimFH";

    public CsimFileHandler(UiccCardApplication app, String aid, CommandsInterface ci) {
        Super(app, aid, ci);
    }

    //@Override
    protected String GetEFPath(Int32 efid) {
        Switch(efid) {
        case EF_SMS:
        case EF_CST:
        case EF_FDN:
        case EF_MSISDN:
        case EF_RUIM_SPN:
        case EF_CSIM_LI:
        case EF_CSIM_MDN:
        case EF_CSIM_IMSIM:
        case EF_CSIM_CDMAHOME:
        case EF_CSIM_EPRL:
        case EF_CSIM_MODEL:
        case EF_MODEL:
        case EF_CSIM_PRL:
        case EF_RUIM_ID:
            return MF_SIM + DF_ADF;
        case EF_CSIM_MSPL:
        case EF_CSIM_MLPL:
            return MF_SIM + DF_TELECOM + DF_MMSS;
        }
        String path = GetCommonIccEFPath(efid);
        If (path == NULL) {
            // The EFids in UICC phone book entries are decided by the card manufacturer.
            // So if we don't match any of the cases above and if its a UICC return
            // the global 3g phone book path.
            return MF_SIM + DF_TELECOM + DF_PHONEBOOK;
        }
        return path;
    }

    //@Override
    protected void Logd(String msg) {
        Rlog->D(LOG_TAG, msg);
    }

    //@Override
    protected void Loge(String msg) {
        Rlog->E(LOG_TAG, msg);
    }
}
