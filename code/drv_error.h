/*****************************************************************************
                ��Ȩ����(C)��2007-2022�����ݻ���ͨ�ż������޹�˾
------------------------------------------------------------------------------
                            error.h
  �� Ʒ ��: VERSION
  ģ �� ��:
  ��������: 2022��3��22��
  ��    ��: x22827
  �ļ�����: error num define

------------------------------------------------------------------------------
   �޸���ʷ
   ����        ����             ����
  --------------------------------------------------------------------------

*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#ifndef _ERROR_H_
#define _ERROR_H_

#define BINDER_SUCCESS                               0x0
#define BINDER_PIPE_NOT_FOUND_USB_DEVICE        0xffff0001
#define BINDER_PIPE_WAIT_EVENT_TERMINATED       0xffff0002
#define BINDER_PIPE_WAIT_EVENT_TIMEOUT          0xffff0003
#define BINDER_IO_READ_ERROR                    0xffff0004
#define BINDER_IO_WRITE_ERROR                   0xffff0005
#define BINDER_IO_CMD_ERROR                     0xffff0006
#define BINDER_USB_ENDPOINT_NULL                0xffff0007
#define BINDER_USB_SEND_URB_ERROR               0xffff0008
#define BINDER_PARAMETER_INVLID                 0xffff0009
#define BINDER_CREATE_WORKQUEUE_ERROR           0xffff000a
#define BINDER_DEVICE_INIT_ERROR                0xffff000b
#define BINDER_IO_INIT_ERROR                    0xffff000c


#endif /* _ERROR_H_ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

