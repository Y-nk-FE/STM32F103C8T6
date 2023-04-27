VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "mscomm32.ocx"
Begin VB.Form Form1 
   BackColor       =   &H00C0C0C0&
   Caption         =   "接收串口数据绘实时曲线-2B "
   ClientHeight    =   7530
   ClientLeft      =   120
   ClientTop       =   345
   ClientWidth     =   12765
   LinkTopic       =   "Form1"
   ScaleHeight     =   7530
   ScaleWidth      =   12765
   Begin MSCommLib.MSComm MSComm1 
      Left            =   480
      Top             =   6840
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000007&
      Height          =   2800
      Index           =   5
      Left            =   8520
      ScaleHeight     =   2745
      ScaleWidth      =   3690
      TabIndex        =   16
      Top             =   3960
      Width           =   3750
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000007&
      Height          =   2800
      Index           =   4
      Left            =   4560
      ScaleHeight     =   2745
      ScaleWidth      =   3690
      TabIndex        =   15
      Top             =   3960
      Width           =   3750
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000007&
      Height          =   2800
      Index           =   3
      Left            =   600
      ScaleHeight     =   2745
      ScaleWidth      =   3690
      TabIndex        =   14
      Top             =   3960
      Width           =   3750
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000007&
      Height          =   2800
      Index           =   2
      Left            =   8520
      ScaleHeight     =   2745
      ScaleWidth      =   3690
      TabIndex        =   13
      Top             =   120
      Width           =   3750
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000007&
      Height          =   2800
      Index           =   1
      Left            =   4560
      ScaleHeight     =   2745
      ScaleWidth      =   3690
      TabIndex        =   12
      Top             =   120
      Width           =   3750
   End
   Begin VB.PictureBox Picture1 
      BackColor       =   &H80000007&
      ForeColor       =   &H000000FF&
      Height          =   2800
      Index           =   0
      Left            =   600
      ScaleHeight     =   2745
      ScaleWidth      =   3690
      TabIndex        =   11
      Top             =   120
      Width           =   3750
   End
   Begin VB.TextBox Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   430
      Index           =   5
      Left            =   10080
      TabIndex        =   10
      Top             =   6840
      Width           =   850
   End
   Begin VB.TextBox Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   430
      Index           =   4
      Left            =   6000
      TabIndex        =   9
      Top             =   6840
      Width           =   850
   End
   Begin VB.TextBox Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   430
      Index           =   3
      Left            =   2040
      TabIndex        =   8
      Top             =   6840
      Width           =   850
   End
   Begin VB.TextBox Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   430
      Index           =   2
      Left            =   10080
      TabIndex        =   7
      Top             =   3000
      Width           =   850
   End
   Begin VB.TextBox Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   430
      Index           =   1
      Left            =   6000
      TabIndex        =   6
      Top             =   3000
      Width           =   850
   End
   Begin VB.TextBox Text 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   430
      Index           =   0
      Left            =   2040
      TabIndex        =   5
      Top             =   3000
      Width           =   850
   End
   Begin VB.Label Label16 
      BackColor       =   &H8000000A&
      Caption         =   " 通道5"
      Height          =   255
      Left            =   9480
      TabIndex        =   27
      Top             =   6960
      Width           =   645
   End
   Begin VB.Label Label15 
      BackColor       =   &H8000000A&
      Caption         =   " 通道4"
      Height          =   255
      Left            =   5280
      TabIndex        =   26
      Top             =   6960
      Width           =   645
   End
   Begin VB.Label Label14 
      BackColor       =   &H8000000A&
      Caption         =   " 通道3"
      Height          =   255
      Left            =   1320
      TabIndex        =   25
      Top             =   6960
      Width           =   645
   End
   Begin VB.Label Label13 
      BackColor       =   &H8000000A&
      Caption         =   " 通道2"
      Height          =   255
      Left            =   9360
      TabIndex        =   24
      Top             =   3120
      Width           =   645
   End
   Begin VB.Label Label12 
      BackColor       =   &H8000000A&
      Caption         =   " 通道1"
      Height          =   255
      Left            =   5280
      TabIndex        =   23
      Top             =   3120
      Width           =   645
   End
   Begin VB.Label Label8 
      BackColor       =   &H8000000A&
      Caption         =   " 通道0"
      Height          =   255
      Left            =   1320
      TabIndex        =   22
      Top             =   3120
      Width           =   645
   End
   Begin VB.Label Label11 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 4"
      Height          =   225
      Left            =   250
      TabIndex        =   21
      Top             =   4958
      Width           =   195
   End
   Begin VB.Label Label10 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 3"
      Height          =   225
      Left            =   250
      TabIndex        =   20
      Top             =   5246
      Width           =   195
   End
   Begin VB.Label Label9 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 2"
      Height          =   225
      Left            =   250
      TabIndex        =   19
      Top             =   5534
      Width           =   195
   End
   Begin VB.Label Label7 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 1"
      Height          =   225
      Left            =   250
      TabIndex        =   18
      Top             =   5822
      Width           =   195
   End
   Begin VB.Label Label6 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 0"
      Height          =   225
      Left            =   250
      TabIndex        =   17
      Top             =   6110
      Width           =   195
   End
   Begin VB.Label Label5 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 0"
      Height          =   220
      Left            =   250
      TabIndex        =   4
      Top             =   2288
      Width           =   200
   End
   Begin VB.Label Label4 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 1"
      Height          =   220
      Left            =   250
      TabIndex        =   3
      Top             =   2000
      Width           =   200
   End
   Begin VB.Label Label3 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 2"
      Height          =   225
      Left            =   250
      TabIndex        =   2
      Top             =   1712
      Width           =   200
   End
   Begin VB.Label Label2 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 3"
      Height          =   220
      Left            =   250
      TabIndex        =   1
      Top             =   1424
      Width           =   200
   End
   Begin VB.Label Label1 
      BackColor       =   &H00C0C0C0&
      Caption         =   " 4"
      Height          =   220
      Left            =   250
      TabIndex        =   0
      Top             =   1136
      Width           =   200
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Option Explicit
Dim a%, b%, Unit%  'a通道号，b接收到的数据值，Unit图片纵座标刻度线间隔
Dim X(6) As Integer    '各通道图片框的X座标
Dim V(6) As Integer    '各通道图片框的X座标

Private Sub Form_Load()
  For a = 0 To 5
    Text(a).TabStop = False       '使焦点跳过各个文本框
  Next a
  Unit = 46                        '图片框的纵座标刻度线间隔
  MSComm1.CommPort = 1             '若在你的PC机运行，CommPort = 6
  MSComm1.Settings = "9600,n,8,1"
  MSComm1.RThreshold = 1          '接收缓冲区收到每一个字符都会使MSComm控件产生OnComm 事件。
  MSComm1.SThreshold = 0
  MSComm1.PortOpen = True
End Sub

Private Sub Form_Activate()
  For a = 0 To 5
    PicInit (a)               '全部图片框初始化，绘X轴、纵座标刻度线
    Text(a).TabStop = False   '使焦点跳过各个文本框
  Next a
End Sub

Private Sub PicInit(a As Integer)  '某个图片框初始化，绘X轴、纵座标刻度
 Picture1(a).ForeColor = RGB(255, 0, 0)                 '设置前景色为红色
 Picture1(a).ScaleHeight = 300                          '设置高度的单位值
 Picture1(a).ScaleMode = 3                              '设置 ScaleMode 为像素
 Picture1(a).Scale (0, Picture1(a).ScaleHeight * 2)-(Picture1(a).ScaleWidth, -Picture1(a).ScaleHeight / 2)
 Picture1(a).Line (0, 0)-(Picture1(a).ScaleWidth, 0)    'X轴
 Picture1(a).Line (0, Unit)-(5, Unit)                   '刻度线1
 Picture1(a).Line (0, 2 * Unit)-(5, 2 * Unit)           '刻度线2
 Picture1(a).Line (0, 3 * Unit)-(5, 3 * Unit)           '刻度线3
 Picture1(a).Line (0, 4 * Unit)-(5, 4 * Unit)           '刻度线4
End Sub

 
Private Sub MSComm1_OnComm()   '串口通信事件响应
  Dim rbuf As Variant
  'On Error Resume Next
  If MSComm1.CommEvent = 2 Then
    MSComm1.InputLen = 0
    rbuf = Trim(MSComm1.Input)
    a = Val(Left(rbuf, 1))
    b = Asc(Right(rbuf, 1))
    If b > 48 And b < 58 Then  ' 是1～9的ASCII码
       b = (b - 48) * 256
       Else
         If b < 71 And b > 64 Then  '是A～F的ASCII码
            b = (b - 55) * 256
         End If
    End If
    Text(a).Text = Format(CStr(b / 1000), "0.00") '数据分配至各通道对应的文本框显示
    V(a) = Unit * (b / 1000)                      '数据值转换为曲线纵座标
    If X(a) = 0 Then
      Picture1(a).Line (0, V(a))-(0, V(a)), RGB(0, 255, 0)
    End If
    Picture1(a).Line -(X(a), V(a)), RGB(0, 255, 0)
    X(a) = X(a) + 5
    If X(a) > Picture1(a).ScaleWidth Then
      X(a) = 0
      Picture1(a).Cls
      PicInit (a)
     End If
  End If
End Sub




























