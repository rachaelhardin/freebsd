/******************************************************************************
 *
 * Module Name: ahamlops - Table of all known AML opcodes
 *
 *****************************************************************************/

/*
 * Copyright (C) 2000 - 2015, Intel Corp.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions, and the following disclaimer,
 *    without modification.
 * 2. Redistributions in binary form must reproduce at minimum a disclaimer
 *    substantially similar to the "NO WARRANTY" disclaimer below
 *    ("Disclaimer") and any redistribution must be conditioned upon
 *    including a substantially similar Disclaimer requirement for further
 *    binary redistribution.
 * 3. Neither the names of the above-listed copyright holders nor the names
 *    of any contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * Alternatively, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") version 2 as published by the Free
 * Software Foundation.
 *
 * NO WARRANTY
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 */

#include "acpihelp.h"

/*
 * AML opcodes with related syntax and grammar information.
 * This table was extracted from the ACPI specification.
 */
const AH_AML_OPCODE         AmlOpcodeInfo[] =
{
    {0x00,   0x00,   "0x00",            "ZeroOp",               "DataObject",   NULL,                                           NULL,
                                                                NULL},
    {0x01,   0x01,   "0x01",            "OneOp",                "DataObject",   NULL,                                           NULL,
                                                                NULL},
    {0x02,   0x05,   "0x02-0x05",       NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x06,   0x06,   "0x06",            "AliasOp",              "TermObject",   "NameString NameString",                        NULL,
                                                                "DefAlias := AliasOp NameString NameString"},
    {0x07,   0x07,   "0x07",            NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x08,   0x08,   "0x08",            "NameOp",               "TermObject",   "NameString DataRefObject",                     NULL,
                                                                "DefName := NameOp NameString DataRefObject"},
    {0x09,   0x09,   "0x09",            NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x0A,   0x0A,   "0x0A",            "BytePrefix",           "DataObject",   "ByteData",                                     NULL,
                                                                "ByteConst := BytePrefix ByteData"},
    {0x0B,   0x0B,   "0x0B",            "WordPrefix",           "DataObject",   "WordData",                                     NULL,
                                                                "WordConst := WordPrefix WordData"},
    {0x0C,   0x0C,   "0x0C",            "DWordPrefix",          "DataObject",   "DWordData",                                    NULL,
                                                                "DWordConst := DWordPrefix DWordData"},
    {0x0D,   0x0D,   "0x0D",            "StringPrefix",         "DataObject",   "AsciiCharList NullChar",                       NULL,
                                                                "String := StringPrefix AsciiCharList NullChar"},
    {0x0E,   0x0E,   "0x0E",            "QWordPrefix",          "DataObject",   "QWordData",                                    NULL,
                                                                "QWordConst := QWordPrefix QWordData"},
    {0x0F,   0x0F,   "0x0F",            NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x10,   0x10,   "0x10",            "ScopeOp",              "TermObject",   "NameString",                                   "TermList",
                                                                "DefScope := ScopeOp PkgLength NameString TermList"},
    {0x11,   0x11,   "0x11",            "BufferOp",             "TermObject",   "TermArg",                                      "ByteList",
                                                                "DefBuffer := BufferOp PkgLength BufferSize ByteList"},
    {0x12,   0x12,   "0x12",            "PackageOp",            "TermObject",   "ByteData",                                     "Package TermList",
                                                                "DefPackage := PackageOp PkgLength NumElements PackageElementList"},
    {0x13,   0x13,   "0x13",            "VarPackageOp",         "TermObject",   "TermArg",                                      "Package TermList",
                                                                "DefVarPackage := VarPackageOp PkgLength VarNumElements PackageElementList"},
    {0x14,   0x14,   "0x14",            "MethodOp",             "TermObject",   "NameString ByteData",                          "TermList",
                                                                "DefMethod := MethodOp PkgLength NameString MethodFlags TermList"},
    {0x15,   0x2D,   "0x15-0x2D",       NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x2E,   0x2E,   "0x2E",            "DualNamePrefix",       "NameObject",   "NameSeg NameSeg",                              NULL,
                                                                "DualNamePath := DualNamePrefix NameSeg NameSeg"},
    {0x2F,   0x2F,   "0x2F",            "MultiNamePrefix",      "NameObject",   "ByteData NameSeg",                             NULL,
                                                                "MultiNamePath := MultiNamePrefix SegCount NameSeg(SegCount)"},
    {0x30,   0x39,   "0x30-0x39",       "DigitChar",            "NameObject",   NULL,                                           NULL,
                                                                NULL},
    {0x3A,   0x40,   "0x3A-0x40",       NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x41,   0x5A,   "0x41-0x5A",       "NameChar",             "NameObject",   NULL,                                           NULL,
                                                                NULL},
    {0x5B,   0x5B,   "0x5B",            "ExtOpPrefix",          "DataObject",   "ByteData",                                     NULL,
                                                                NULL},
    {0x5B00, 0x5B00, "0x5B00",          NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x5B01, 0x5B01, "0x5B01",          "MutexOp",              "TermObject",   "NameString ByteData",                          NULL,
                                                                "DefMutex := MutexOp NameString SyncFlags"},
    {0x5B02, 0x5B02, "0x5B02",          "EventOp",              "TermObject",   "NameString",                                   NULL,
                                                                "DefEvent := EventOp NameString"},
    {0x5B12, 0x5B12, "0x5B12",          "CondRefOfOp",          "TermObject",   "SuperName SuperName",                          NULL,
                                                                "DefCondRefOf := CondRefOfOp SuperName Target"},
    {0x5B13, 0x5B13, "0x5B13",          "CreateFieldOp",        "TermObject",   "TermArg TermArg TermArg NameString",           NULL,
                                                                "DefCreateField := CreateFieldOp SourceBuff BitIndex NumBits NameString"},
    {0x5B1F, 0x5B1F, "0x5B1F",          "LoadTableOp",          "TermObject",   "TermArg TermArg TermArg TermArg TermArg TermArg",      NULL,
                                                                "DefLoadTable := LoadTableOp TermArg TermArg TermArg TermArg TermArg TermArg"},
    {0x5B20, 0x5B20, "0x5B20",          "LoadOp",               "TermObject",   "NameString SuperName",                         NULL,
                                                                "DefLoad := LoadOp NameString DDBHandleObject"},
    {0x5B21, 0x5B21, "0x5B21",          "StallOp",              "TermObject",   "TermArg",                                      NULL,
                                                                "DefStall := StallOp UsecTime"},
    {0x5B22, 0x5B22, "0x5B22",          "SleepOp",              "TermObject",   "TermArg",                                      NULL,
                                                                "DefSleep := SleepOp MsecTime"},
    {0x5B23, 0x5B23, "0x5B23",          "AcquireOp",            "TermObject",   "SuperName WordData",                           NULL,
                                                                "DefAcquire := AcquireOp MutexObject Timeout"},
    {0x5B24, 0x5B24, "0x5B24",          "SignalOp",             "TermObject",   "SuperName",                                    NULL,
                                                                "DefSignal := SignalOp EventObject"},
    {0x5B25, 0x5B25, "0x5B25",          "WaitOp",               "TermObject",   "SuperName TermArg",                            NULL,
                                                                "DefWait := WaitOp EventObject Operand"},
    {0x5B26, 0x5B26, "0x5B26",          "ResetOp",              "TermObject",   "SuperName",                                    NULL,
                                                                "DefReset := ResetOp EventObject"},
    {0x5B27, 0x5B27, "0x5B27",          "ReleaseOp",            "TermObject",   "SuperName",                                    NULL,
                                                                "DefRelease := ReleaseOp MutexObject"},
    {0x5B28, 0x5B28, "0x5B28",          "FromBCDOp",            "TermObject",   "TermArg Target",                               NULL,
                                                                "DefFromBCD := FromBCDOp BCDValue Target"},
    {0x5B29, 0x5B29, "0x5B29",          "ToBCD",                "TermObject",   "TermArg Target",                               NULL,
                                                                "DefToBCD := ToBCDOp Operand Target"},
    {0x5B2A, 0x5B2A, "0x5B2A",          "UnloadOp",             "TermObject",   "SuperName",                                    NULL,
                                                                "DefUnload := UnloadOp DDBHandleObject"},
    {0x5B30, 0x5B30, "0x5B30",          "RevisionOp",           "DataObject",   NULL,                                           NULL,
                                                                NULL},
    {0x5B31, 0x5B31, "0x5B31",          "DebugOp",              "DebugObject",  NULL,                                           NULL,
                                                                NULL},
    {0x5B32, 0x5B32, "0x5B32",          "FatalOp",              "TermObject",   "ByteData DWordData TermArg",                   NULL,
                                                                "DefFatal := FatalOp FatalType FatalCode FatalArg"},
    {0x5B33, 0x5B33, "0x5B33",          "TimerOp",              "TermObject",   NULL,                                           NULL,
                                                                "DefTimer := TimerOp"},
    {0x5B80, 0x5B80, "0x5B80",          "OperationRegionOp",    "TermObject",   "NameString ByteData TermArg TermArg",          NULL,
                                                                "DefOpRegion := OpRegionOp NameString RegionSpace RegionOffset RegionLen"},
    {0x5B81, 0x5B81, "0x5B81",          "FieldOp",              "TermObject",   "NameString ByteData",                          "FieldList",
                                                                "DefField := FieldOp PkgLength NameString FieldFlags FieldList"},
    {0x5B82, 0x5B82, "0x5B82",          "DeviceOp",             "TermObject",   "NameString",                                   "ObjectList",
                                                                "DefDevice := DeviceOp PkgLength NameString ObjectList"},
    {0x5B83, 0x5B83, "0x5B83",          "ProcessorOp",          "TermObject",   "NameString ByteData DWordData ByteData",       "ObjectList",
                                                                "DefProcessor := ProcessorOp PkgLength NameString ProcID PblkAddr PblkLen ObjectList"},
    {0x5B84, 0x5B84, "0x5B84",          "PowerResOp",           "TermObject",   "NameString ByteData WordData",                 "ObjectList",
                                                                "DefPowerRes := PowerResOp PkgLength NameString SystemLevel ResourceOrder ObjectList"},
    {0x5B85, 0x5B85, "0x5B85",          "ThermalZoneOp",        "TermObject",   "NameString",                                   "ObjectList",
                                                                "DefThermalZone := ThermalZoneOp PkgLength NameString ObjectList"},
    {0x5B86, 0x5B86, "0x5B86",          "IndexFieldOp",         "TermObject",   "NameString NameString ByteData",               "FieldList",
                                                                "DefIndexField := IndexFieldOp PkgLength NameString NameString FieldFlags FieldList"},
    {0x5B87, 0x5B87, "0x5B87",          "BankFieldOp",          "TermObject",   "NameString NameString TermArg ByteData",       "FieldList",
                                                                "DefBankField := BankFieldOp PkgLength NameString NameString BankValue FieldFlags FieldList"},
    {0x5B88, 0x5B88, "0x5B88",          "DataRegionOp",         "TermObject",   "NameString TermArg TermArg TermArg",           NULL,
                                                                "DefDataRegion := DataRegionOp NameString TermArg TermArg TermArg"},
    {0x5B89, 0x5BFF, "0x5B89-0x5BFF",   NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x5C,   0x5C,   "0x5C",            "RootChar",             "NameObject",   NULL,                                           NULL,
                                                                NULL},
    {0x5D,   0x5D,   "0x5D",            NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x5E,   0x5E,   "0x5E",            "ParentPrefixChar",     "NameObject",   NULL,                                           NULL,
                                                                NULL},
    {0x5F,   0x5F,   "0x5F",            "NameChar",             "NameObject",   NULL,                                           NULL,
                                                                NULL},
    {0x60,   0x60,   "0x60",            "Local0Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x61,   0x61,   "0x61",            "Local1Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x62,   0x62,   "0x62",            "Local2Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x63,   0x63,   "0x63",            "Local3Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x64,   0x64,   "0x64",            "Local4Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x65,   0x65,   "0x65",            "Local5Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x66,   0x66,   "0x66",            "Local6Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x67,   0x67,   "0x67",            "Local7Op",             "LocalObject",  NULL,                                           NULL,
                                                                NULL},
    {0x68,   0x68,   "0x68",            "Arg0Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x69,   0x69,   "0x69",            "Arg1Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x6A,   0x6A,   "0x6A",            "Arg2Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x6B,   0x6B,   "0x6B",            "Arg3Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x6C,   0x6C,   "0x6C",            "Arg4Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x6D,   0x6D,   "0x6D",            "Arg5Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x6E,   0x6E,   "0x6E",            "Arg6Op",               "ArgObject",    NULL,                                           NULL,
                                                                NULL},
    {0x6F,   0x6F,   "0x6F",            NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x70,   0x70,   "0x70",            "StoreOp",              "TermObject",   "TermArg SuperName",                            NULL,
                                                                "DefStore := StoreOp TermArg SuperName"},
    {0x71,   0x71,   "0x71",            "RefOfOp",              "TermObject",   "SuperName ",                                   NULL,
                                                                "DefRefOf := RefOfOp SuperName"},
    {0x72,   0x72,   "0x72",            "AddOp",                "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefAdd := AddOp Operand Operand Target"},
    {0x73,   0x73,   "0x73",            "ConcatOp",             "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefConcat := ConcatOp Data Data Target"},
    {0x74,   0x74,   "0x74",            "SubtractOp",           "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefSubtract := SubtractOp Operand Operand Target"},
    {0x75,   0x75,   "0x75",            "IncrementOp",          "TermObject",   "SuperName",                                    NULL,
                                                                "DefIncrement := IncrementOp SuperName"},
    {0x76,   0x76,   "0x76",            "DecrementOp",          "TermObject",   "SuperName",                                    NULL,
                                                                "DefDecrement := DecrementOp SuperName"},
    {0x77,   0x77,   "0x77",            "MultiplyOp",           "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefMultiply := MultiplyOp Operand Operand Target"},
    {0x78,   0x78,   "0x78",            "DivideOp",             "TermObject",   "TermArg TermArg Target Target",                NULL,
                                                                "DefDivide := DivideOp Dividend Divisor Remainder Quotient"},
    {0x79,   0x79,   "0x79",            "ShiftLeftOp",          "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefShiftLeft := ShiftLeftOp Operand ShiftCount Target"},
    {0x7A,   0x7A,   "0x7A",            "ShiftRightOp",         "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefShiftRight := ShiftRightOp Operand ShiftCount Target"},
    {0x7B,   0x7B,   "0x7B",            "AndOp",                "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefAnd := AndOp Operand Operand Target"},
    {0x7C,   0x7C,   "0x7C",            "NandOp",               "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefNAnd := NandOp Operand Operand Target"},
    {0x7D,   0x7D,   "0x7D",            "OrOp",                 "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefOr := OrOp Operand Operand Target"},
    {0x7E,   0x7E,   "0x7E",            "NorOp",                "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefNOr := NorOp Operand Operand Target"},
    {0x7F,   0x7F,   "0x7F",            "XorOp",                "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefXOr := XorOp Operand Operand Target"},
    {0x80,   0x80,   "0x80",            "NotOp",                "TermObject",   "TermArg Target",                               NULL,
                                                                "DefNot := NotOp Operand Target"},
    {0x81,   0x81,   "0x81",            "FindSetLeftBitOp",     "TermObject",   "TermArg Target",                               NULL,
                                                                "DefFindSetLeftBit := FindSetLeftBitOp Operand Target"},
    {0x82,   0x82,   "0x82",            "FindSetRightBitOp",    "TermObject",   "TermArg Target",                               NULL,
                                                                "DefFindSetRightBit := FindSetRightBitOp Operand Target"},
    {0x83,   0x83,   "0x83",            "DerefOfOp",            "TermObject",   "TermArg",                                      NULL,
                                                                "DefDerefOf := DerefOfOp ObjReference"},
    {0x84,   0x84,   "0x84",            "ConcatResOp",          "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefConcatRes := ConcatResOp BufData BufData Target"},
    {0x85,   0x85,   "0x85",            "ModOp",                "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefMod := ModOp Dividend Divisor Target"},
    {0x86,   0x86,   "0x86",            "NotifyOp",             "TermObject",   "SuperName TermArg",                            NULL,
                                                                "DefNotify := NotifyOp NotifyObject NotifyValue"},
    {0x87,   0x87,   "0x87",            "SizeOfOp",             "TermObject",   "SuperName",                                    NULL,
                                                                "DefSizeOf := SizeOfOp SuperName"},
    {0x88,   0x88,   "0x88",            "IndexOp",              "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefIndex := IndexOp BuffPkgStrObj IndexValue Target"},
    {0x89,   0x89,   "0x89",            "MatchOp",              "TermObject",   "TermArg ByteData TermArg ByteData TermArg TermArg",    NULL,
                                                                "DefMatch := MatchOp SearchPkg MatchOpcode Operand MatchOpcode Operand StartIndex"},
    {0x8A,   0x8A,   "0x8A",            "CreateDWordFieldOp",   "TermObject",   "TermArg TermArg NameString",                   NULL,
                                                                "DefCreateDWordField := CreateDWordFieldOp SourceBuff ByteIndex NameString"},
    {0x8B,   0x8B,   "0x8B",            "CreateWordFieldOp",    "TermObject",   "TermArg TermArg NameString",                   NULL,
                                                                "DefCreateWordField := CreateWordFieldOp SourceBuff ByteIndex NameString"},
    {0x8C,   0x8C,   "0x8C",            "CreateByteFieldOp",    "TermObject",   "TermArg TermArg NameString",                   NULL,
                                                                "DefCreateByteField := CreateByteFieldOp SourceBuff ByteIndex NameString"},
    {0x8D,   0x8D,   "0x8D",            "CreateBitFieldOp",     "TermObject",   "TermArg TermArg NameString",                   NULL,
                                                                "DefCreateBitField := CreateBitFieldOp SourceBuff BitIndex NameString"},
    {0x8E,   0x8E,   "0x8E",            "ObjectTypeOp",         "TermObject",   "SuperName",                                    NULL,
                                                                "DefObjectType := ObjectTypeOp SuperName"},
    {0x8F,   0x8F,   "0x8F",            "CreateQWordFieldOp",   "TermObject",   "TermArg TermArg NameString",                   NULL,
                                                                "DefCreateQWordField := CreateQWordFieldOp SourceBuff ByteIndex NameString"},
    {0x90,   0x90,   "0x90",            "LAndOp",               "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLAnd := LandOp Operand Operand"},
    {0x91,   0x91,   "0x91",            "LOrOp",                "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLOr := LorOp Operand Operand"},
    {0x92,   0x92,   "0x92",            "LNotOp",               "TermObject",   "TermArg",                                      NULL,
                                                                "DefLNot := LnotOp Operand"},
    {0x9293, 0x9293, "0x9293",          "LNotEqualOp",          "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLNotEqual := LnotEqualOp Operand Operand"},
    {0x9294, 0x9294, "0x9294",          "LLessEqualOp",         "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLLessEqual := LlessEqualOp Operand Operand"},
    {0x9295, 0x9295, "0x9295",          "LGreaterEqualOp",      "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLGreaterEqual := LgreaterEqualOp Operand Operand"},
    {0x93,   0x93,   "0x93",            "LEqualOp",             "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLEqual := LequalOp Operand Operand"},
    {0x94,   0x94,   "0x94",            "LGreaterOp",           "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLGreater := LgreaterOp Operand Operand"},
    {0x95,   0x95,   "0x95",            "LLessOp",              "TermObject",   "TermArg TermArg",                              NULL,
                                                                "DefLLess := LlessOp Operand Operand"},
    {0x96,   0x96,   "0x96",            "ToBufferOp",           "TermObject",   "TermArg Target",                               NULL,
                                                                "DefToBuffer := ToBufferOp Operand Target"},
    {0x97,   0x97,   "0x97",            "ToDecimalStringOp",    "TermObject",   "TermArg Target",                               NULL,
                                                                "DefToDecimalString := ToDecimalStringOp Operand Target"},
    {0x98,   0x98,   "0x98",            "ToHexStringOp",        "TermObject",   "TermArg Target",                               NULL,
                                                                "DefToHexString := ToHexStringOp Operand Target"},
    {0x99,   0x99,   "0x99",            "ToIntegerOp",          "TermObject",   "TermArg Target",                               NULL,
                                                                "DefToInteger := ToIntegerOp Operand Target"},
    {0x9A,   0x9B,   "0x9A-0x9B",       NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0x9C,   0x9C,   "0x9C",            "ToStringOp",           "TermObject",   "TermArg TermArg Target",                       NULL,
                                                                "DefToString := ToStringOp TermArg LengthArg Target"},
    {0x9D,   0x9D,   "0x9D",            "CopyObjectOp",         "TermObject",   "TermArg SimpleName",                           NULL,
                                                                "DefCopyObject := CopyObjectOp TermArg SimpleName"},
    {0x9E,   0x9E,   "0x9E",            "MidOp",                "TermObject",   "TermArg TermArg TermArg Target",               NULL,
                                                                "DefMid := MidOp MidObj TermArg TermArg Target"},
    {0x9F,   0x9F,   "0x9F",            "ContinueOp",           "TermObject",   NULL,                                           NULL,
                                                                "DefContinue := ContinueOp"},
    {0xA0,   0xA0,   "0xA0",            "IfOp",                 "TermObject",   "TermArg",                                      "TermList",
                                                                "DefIfElse := IfOp PkgLength Predicate TermList DefElse"},
    {0xA1,   0xA1,   "0xA1",            "ElseOp",               "TermObject",   NULL,                                           "TermList",
                                                                "DefElse := Nothing | <ElseOp PkgLength TermList>"},
    {0xA2,   0xA2,   "0xA2",            "WhileOp",              "TermObject",   "TermArg",                                      "TermList",
                                                                "DefWhile := WhileOp PkgLength Predicate TermList"},
    {0xA3,   0xA3,   "0xA3",            "NoopOp",               "TermObject",   NULL,                                           NULL,
                                                                "DefNoop := NoopOp"},
    {0xA4,   0xA4,   "0xA4",            "ReturnOp",             "TermObject",   "TermArg",                                      NULL,
                                                                "DefReturn := ReturnOp ArgObject"},
    {0xA5,   0xA5,   "0xA5",            "BreakOp",              "TermObject",   NULL,                                           NULL,
                                                                "DefBreak := BreakOp"},
    {0xA6,   0xCB,   "0xA6-0xCB",       NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0xCC,   0xCC,   "0xCC",            "BreakPointOp",         "TermObject",   NULL,                                           NULL,
                                                                "DefBreakPoint := BreakPointOp"},
    {0xCD,   0xFE,   "0xCD-0xFE",       NULL,                   NULL,           NULL,                                           NULL,
                                                                NULL},
    {0xFF,   0xFF,   "0xFF",            "OnesOp",               "DataObject",   NULL,                                           NULL,
                                                                NULL},
    {0, 0, NULL,  NULL, NULL, NULL, NULL, NULL}
};
