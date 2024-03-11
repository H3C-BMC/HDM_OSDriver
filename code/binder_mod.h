/*****************************************************************************
                ��Ȩ����(C)��2007-2022�����ݻ���ͨ�ż������޹�˾
------------------------------------------------------------------------------
                            binder_mod.h
  �� Ʒ ��: VERSION
  ģ �� ��:
  ��������: 2022��3��22��
  ��    ��: x22827
  �ļ�����: usb binder header

------------------------------------------------------------------------------
   �޸���ʷ
   ����        ����             ����
  --------------------------------------------------------------------------

*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#ifndef _USBPIPE_MOD_H_
#define _USBPIPE_MOD_H_

#define USB_BINDER_CTRL_CMD_CONNETCT       0    /* �½��Ự���� */
#define USB_BINDER_CTRL_CMD_DISCONNECT    1     /* �Ͽ��Ự���� */
#define USB_BINDER_CTRL_CMD_SEND_OSINFO    2    /* ����OSϵͳ��Ϣ */
#define USB_BINDER_CTRL_CMD_CLEAR_OSINFO   3    /* ���OSϵͳ��Ϣ */

#define USB_BINDER_PKT_HEAD_LEN            4    /* �Զ����ͷ���� */

/* ioctl cmd */
typedef enum
{
    IOCTL_BINDER_INIT = 0x9000,
    IOCTL_BINDER_READ,
    IOCTL_BINDER_WRITE,
    IOCTL_BINDER_EXIT,
}BINDER_IOCTL_CMD_E;

typedef enum
{
    DIR_OUT,
    DIR_IN,
}BINDER_DIR_E;

typedef struct tagBinder_Mod
{
    dma_addr_t ulUsbBufOutPhysAddr;
    dma_addr_t ulUsbBufInPhysAddr;
    CHAR *pcUsbBufVirtOut;
    CHAR *pcUsbBufVirtIn;
    UINT uiUsbBufLen;
    struct urb *pstUrbOut;
    struct urb *pstUrbIn;
}BINDER_MOD_S;

typedef struct tagBinder_Work
{
    struct work_struct stWork;
    INT iDirChl;
}BINDER_WORK_S;

typedef struct tagBinder_Pkt
{
    CHAR *pcData;
    UINT uiTimeout;
    UINT uiDataLen;
}BINDER_PKT_S;

typedef struct tagBinder_Private_Data
{
    USHORT usSessionID;
    PIPE_QUEUE_T *pstRecvQue;
}BINDER_PRIVATE_DATA_S;


#ifdef HAVE_UNLOCKED_IOCTL
  #if HAVE_UNLOCKED_IOCTL
    #define USE_UNLOCKED_IOCTL
  #endif
#endif

#define DEVICE_NAME "hdmdrv"

#ifdef  DEBUG_BINDER
#define DEBUG_PRINT(...) printk(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

#endif /* _USBPIPE_MOD_H_ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

