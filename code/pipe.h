/*****************************************************************************
                ��Ȩ����(C)��2007-2022�����ݻ���ͨ�ż������޹�˾
------------------------------------------------------------------------------
                            pipe.h
  �� Ʒ ��: VERSION
  ģ �� ��:
  ��������: 2022��3��22��
  ��    ��: x22827
  �ļ�����: data save

------------------------------------------------------------------------------
   �޸���ʷ
   ����        ����             ����
  --------------------------------------------------------------------------

*****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */


#ifndef _PIPE_H_
#define _PIPE_H_


#define MAX_PIPE_DATA_SIZE 1024*16

#define MAX_ENDPOINT_SIZE 512
#define DATA_QUEUE_SIZE   64
#define SCSI_CSW_SIZE     13

typedef struct
{
    USHORT      usId;
    UCHAR       aaucEntry[DATA_QUEUE_SIZE][MAX_PIPE_DATA_SIZE];
    UINT        uiEntrySize [DATA_QUEUE_SIZE];
    INT         iWrIndex;
    INT         iRdIndex;
    INT         iCount;
    BOOL_T      bAbnormal;
    spinlock_t  stLock;
    wait_queue_head_t stWait;
    wait_queue_head_t stWrWait;
    struct list_head  stPipeList;
} PIPE_QUEUE_T;

struct usb_pipe_device
{
    INT (*UsbSendData)(UCHAR *pucBuffer, UINT uiLen);
    UINT uiMaxCount;
};


VOID PipeTxHandler (VOID);
VOID PipeRxHandler (UCHAR *pucBuffer, UINT uiCount, INT iStatus);
VOID PipeSendDataAfterRun(VOID);
INT IsPipeSendComplete(VOID);
VOID init_pipe(struct usb_pipe_device *pstDevice);
VOID init_pipe_mod(VOID);
VOID exit_pipe(VOID);
INT ClearPipeDataQueue (PIPE_QUEUE_T *pstPipeQue);
PIPE_QUEUE_T *Pipe_malloc(VOID);
VOID Pipe_free(PIPE_QUEUE_T *pstPipeQue);

ssize_t  PipeWriteByKernel(USHORT usId, const CHAR *pcBuf, size_t ulCount, UINT uiTimeout);
ssize_t  PipeRead(USHORT usId, CHAR *pcBuf, size_t ulCount, UINT uiTimeout);
ssize_t  PipeWrite(USHORT usId, const CHAR __user *pcBuf, size_t ulCount, UINT uiTimeout);
INT IsUsbDetected(VOID);

#endif /* _PIPE_H_ */

#ifdef __cplusplus
}
#endif /* __cplusplus */

