/*****************************************************************************
                ��Ȩ����(C)��2007-2022�����ݻ���ͨ�ż������޹�˾
------------------------------------------------------------------------------
                            type.h
  �� Ʒ ��: VERSION
  ģ �� ��:
  ��������: 2022��3��18��
  ��    ��: x22827
  �ļ�����: �������ݶ���

------------------------------------------------------------------------------
   �޸���ʷ
   ����        ����             ����
  --------------------------------------------------------------------------

*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#ifndef _TYPE_H_
#define _TYPE_H_

#ifdef __GNUC__
#define PACKED __attribute__ ((packed))
#else
#define PACKED
#pragma pack(1)
#endif



#define UCHAR           unsigned char
#define USHORT          unsigned short
#define UINT            unsigned int
#define ULONG           unsigned long
#define DULONG          unsigned long long

#define CHAR            char
#define SHORT           short
#define INT             int
#define LONG            long
#define DLONG           long long

#define BOOL_T          bool

#define VOID            void
#define STATIC          static

#define BOOL_TRUE       true
#define BOOL_FALSE      false



#endif /* _TYPE_H_ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

