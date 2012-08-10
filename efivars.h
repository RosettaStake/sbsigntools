/*
 * Copyright (C) 2012 Jeremy Kerr <jeremy.kerr@canonical.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the OpenSSL
 * library under certain conditions as described in each individual source file,
 * and distribute linked combinations including the two.
 *
 * You must obey the GNU General Public License in all respects for all
 * of the code used other than OpenSSL. If you modify file(s) with this
 * exception, you may extend this exception to your version of the
 * file(s), but you are not obligated to do so. If you do not wish to do
 * so, delete this exception statement from your version. If you delete
 * this exception statement from all source files in the program, then
 * also delete it here.
 */
#ifndef EFI_VARAUTH_H
#define EFI_VARAUTH_H

#include <efi/efi.h>

#define EFI_CERT_TYPE_PKCS7_GUID \
	{0x4aafd29d, 0x68df, 0x49ee, \
	{0x8a, 0xa9, 0x34, 0x7d, 0x37, 0x56, 0x65, 0xa7}}

typedef struct {
	UINT32		dwLength;
	UINT16		wRevision;
	UINT16		wCertificateType;
	UINT8		bCertificate[];
} WIN_CERTIFICATE;

typedef struct {
	WIN_CERTIFICATE	Hdr;
	EFI_GUID	CertType;
	UINT8		CertData[];
} WIN_CERTIFICATE_UEFI_GUID;

typedef struct {
	EFI_TIME			TimeStamp;
	WIN_CERTIFICATE_UEFI_GUID	AuthInfo;
} EFI_VARIABLE_AUTHENTICATION_2;


typedef struct {
	EFI_GUID	SignatureOwner;
	UINT8		SignatureData[];
} EFI_SIGNATURE_DATA;

typedef struct {
	EFI_GUID	SignatureType;
	UINT32		SignatureListSize;
	UINT32		SignatureHeaderSize;
	UINT32		SignatureSize;
} EFI_SIGNATURE_LIST;

#endif /* EFI_VARAUTH_H */

