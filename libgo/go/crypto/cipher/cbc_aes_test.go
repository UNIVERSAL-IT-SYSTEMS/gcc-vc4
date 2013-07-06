// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// CBC AES test vectors.

// See U.S. National Institute of Standards and Technology (NIST)
// Special Publication 800-38A, ``Recommendation for Block Cipher
// Modes of Operation,'' 2001 Edition, pp. 24-29.

package cipher_test

import (
	"bytes"
	"crypto/aes"
	"crypto/cipher"
	"testing"
)

var cbcAESTests = []struct {
	name string
	key  []byte
	iv   []byte
	in   []byte
	out  []byte
}{
	// NIST SP 800-38A pp 27-29
	{
		"CBC-AES128",
		commonKey128,
		commonIV,
		commonInput,
		[]byte{
			0x76, 0x49, 0xab, 0xac, 0x81, 0x19, 0xb2, 0x46, 0xce, 0xe9, 0x8e, 0x9b, 0x12, 0xe9, 0x19, 0x7d,
			0x50, 0x86, 0xcb, 0x9b, 0x50, 0x72, 0x19, 0xee, 0x95, 0xdb, 0x11, 0x3a, 0x91, 0x76, 0x78, 0xb2,
			0x73, 0xbe, 0xd6, 0xb8, 0xe3, 0xc1, 0x74, 0x3b, 0x71, 0x16, 0xe6, 0x9e, 0x22, 0x22, 0x95, 0x16,
			0x3f, 0xf1, 0xca, 0xa1, 0x68, 0x1f, 0xac, 0x09, 0x12, 0x0e, 0xca, 0x30, 0x75, 0x86, 0xe1, 0xa7,
		},
	},
	{
		"CBC-AES192",
		commonKey192,
		commonIV,
		commonInput,
		[]byte{
			0x4f, 0x02, 0x1d, 0xb2, 0x43, 0xbc, 0x63, 0x3d, 0x71, 0x78, 0x18, 0x3a, 0x9f, 0xa0, 0x71, 0xe8,
			0xb4, 0xd9, 0xad, 0xa9, 0xad, 0x7d, 0xed, 0xf4, 0xe5, 0xe7, 0x38, 0x76, 0x3f, 0x69, 0x14, 0x5a,
			0x57, 0x1b, 0x24, 0x20, 0x12, 0xfb, 0x7a, 0xe0, 0x7f, 0xa9, 0xba, 0xac, 0x3d, 0xf1, 0x02, 0xe0,
			0x08, 0xb0, 0xe2, 0x79, 0x88, 0x59, 0x88, 0x81, 0xd9, 0x20, 0xa9, 0xe6, 0x4f, 0x56, 0x15, 0xcd,
		},
	},
	{
		"CBC-AES256",
		commonKey256,
		commonIV,
		commonInput,
		[]byte{
			0xf5, 0x8c, 0x4c, 0x04, 0xd6, 0xe5, 0xf1, 0xba, 0x77, 0x9e, 0xab, 0xfb, 0x5f, 0x7b, 0xfb, 0xd6,
			0x9c, 0xfc, 0x4e, 0x96, 0x7e, 0xdb, 0x80, 0x8d, 0x67, 0x9f, 0x77, 0x7b, 0xc6, 0x70, 0x2c, 0x7d,
			0x39, 0xf2, 0x33, 0x69, 0xa9, 0xd9, 0xba, 0xcf, 0xa5, 0x30, 0xe2, 0x63, 0x04, 0x23, 0x14, 0x61,
			0xb2, 0xeb, 0x05, 0xe2, 0xc3, 0x9b, 0xe9, 0xfc, 0xda, 0x6c, 0x19, 0x07, 0x8c, 0x6a, 0x9d, 0x1b,
		},
	},
}

func TestCBC_AES(t *testing.T) {
	for _, tt := range cbcAESTests {
		test := tt.name

		c, err := aes.NewCipher(tt.key)
		if err != nil {
			t.Errorf("%s: NewCipher(%d bytes) = %s", test, len(tt.key), err)
			continue
		}

		encrypter := cipher.NewCBCEncrypter(c, tt.iv)
		d := make([]byte, len(tt.in))
		encrypter.CryptBlocks(d, tt.in)
		if !bytes.Equal(tt.out, d) {
			t.Errorf("%s: CBCEncrypter\nhave %x\nwant %x", test, d, tt.out)
		}

		decrypter := cipher.NewCBCDecrypter(c, tt.iv)
		p := make([]byte, len(d))
		decrypter.CryptBlocks(p, d)
		if !bytes.Equal(tt.in, p) {
			t.Errorf("%s: CBCDecrypter\nhave %x\nwant %x", test, d, tt.in)
		}
	}
}
