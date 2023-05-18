import serial
import time


try:
    # 通讯串口配置
    port_name_sen = "com7"     # 传感器
    port_name_emd = "com3"     # 驱动
    sen = serial.Serial(port=port_name_sen, baudrate=115200, timeout=0.01, parity=serial.PARITY_NONE, bytesize=8)
    emd = serial.Serial(port=port_name_emd, baudrate=115200, timeout=0.01, parity=serial.PARITY_NONE, bytesize=8)
    print(sen)
    print(emd)

    print('-'*160)

    # 启动
    emd.write(b'Stable_1st\r\n')
    n = 1

    while True:
        print(n)
        n += 1
        time.sleep(0.001)
        if emd.in_waiting:
            message = emd.readline().decode('gbk')
            print(message)
            if message == 'Stable_1st_Finish\r\n':
                sen.write(b'Read_1st\r\n')
            if message == 'Stable_2nd_Finish\r\n':
                sen.write(b'Read_2nd\r\n')
            if message == 'Stable_3rd_Finish\r\n':
                sen.write(b'Read_3rd\r\n')
            emd.flushInput()

        if sen.in_waiting:
            message = sen.readline().decode('gbk')
            print(message)
            if message == 'Read_1st_Finish\r\n':
                emd.write(b'Stable_2nd\r\n')
            if message == 'Read_2nd_Finish\r\n':
                emd.write(b'Stable_3rd\r\n')
            if message == 'Read_3rd_Finish\r\n':
                emd.write(b'Stable_1st\r\n')
            if message == 'Read_All_Finish\r\n':
                emd.close()
                sen.close()
                break
            sen.flushInput()


except Exception as e:
    print('error', e)
