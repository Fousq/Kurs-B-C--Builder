object MainForm: TMainForm
  Left = 276
  Top = 273
  Width = 966
  Height = 640
  Caption = 'MainForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = 48
    Width = 473
    Height = 345
    ActivePage = NewbornsSheet
    TabIndex = 0
    TabOrder = 0
    object NewbornsSheet: TTabSheet
      Caption = 'NewbornsSheet'
      object DBGrid1: TDBGrid
        Left = 0
        Top = 0
        Width = 465
        Height = 313
        DataSource = DataModule1.NewbornsDS
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit]
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
    object DeadsSheet: TTabSheet
      Caption = 'DeadsSheet'
      ImageIndex = 1
      object DBGrid2: TDBGrid
        Left = 0
        Top = 0
        Width = 465
        Height = 313
        DataSource = DataModule1.DeadsDS
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'MS Sans Serif'
        TitleFont.Style = []
      end
    end
  end
  object AddGB: TGroupBox
    Left = 552
    Top = 488
    Width = 305
    Height = 465
    Caption = 'AddGB'
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 40
      Width = 136
      Height = 13
      Caption = #1060#1072#1084#1080#1083#1080#1103', '#1048#1084#1103', '#1054#1090#1095#1077#1089#1090#1074#1086': '
    end
    object Label2: TLabel
      Left = 16
      Top = 64
      Width = 26
      Height = 13
      Caption = #1055#1086#1083': '
    end
    object Label3: TLabel
      Left = 16
      Top = 96
      Width = 77
      Height = 13
      Caption = #1044#1072#1090#1072' '#1088#1086#1076#1077#1085#1080#1103': '
    end
    object Label4: TLabel
      Left = 16
      Top = 128
      Width = 91
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1088#1086#1078#1076#1077#1085#1080#1103': '
    end
    object Label5: TLabel
      Left = 16
      Top = 160
      Width = 32
      Height = 13
      Caption = 'Label5'
    end
  end
  object EditGB: TGroupBox
    Left = 216
    Top = 488
    Width = 305
    Height = 465
    Caption = 'EditGB'
    TabOrder = 2
  end
  object DeleteGB: TGroupBox
    Left = 8
    Top = 504
    Width = 185
    Height = 105
    Caption = 'DeleteGB'
    TabOrder = 3
  end
  object AddButton: TButton
    Left = 24
    Top = 424
    Width = 75
    Height = 25
    Caption = 'AddButton'
    TabOrder = 4
    OnClick = AddButtonClick
  end
  object EditButton: TButton
    Left = 120
    Top = 424
    Width = 75
    Height = 25
    Caption = 'EditButton'
    TabOrder = 5
  end
  object DeleteButton: TButton
    Left = 216
    Top = 424
    Width = 75
    Height = 25
    Caption = 'DeleteButton'
    TabOrder = 6
  end
  object InformationPanel: TPanel
    Left = 520
    Top = 52
    Width = 369
    Height = 377
    Caption = 'InformationPanel'
    TabOrder = 7
    object Label6: TLabel
      Left = 16
      Top = 16
      Width = 136
      Height = 13
      Caption = #1060#1072#1084#1080#1083#1080#1103', '#1048#1084#1103', '#1054#1090#1095#1077#1089#1090#1074#1086': '
    end
    object Label7: TLabel
      Left = 16
      Top = 40
      Width = 26
      Height = 13
      Caption = #1055#1086#1083': '
    end
    object Label8: TLabel
      Left = 16
      Top = 64
      Width = 85
      Height = 13
      Caption = #1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103': '
    end
    object Label9: TLabel
      Left = 16
      Top = 88
      Width = 91
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1088#1086#1078#1076#1077#1085#1080#1103': '
    end
    object Label10: TLabel
      Left = 16
      Top = 112
      Width = 72
      Height = 13
      Caption = #1044#1072#1090#1072' '#1089#1084#1077#1088#1090#1080': '
    end
    object Label11: TLabel
      Left = 16
      Top = 136
      Width = 78
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1089#1084#1077#1088#1090#1080': '
    end
    object Label12: TLabel
      Left = 16
      Top = 160
      Width = 91
      Height = 13
      Caption = #1055#1088#1080#1095#1080#1085#1099' '#1089#1084#1077#1088#1090#1080': '
    end
    object DBText1: TDBText
      Left = 160
      Top = 16
      Width = 42
      Height = 13
      AutoSize = True
      DataField = 'FIO'
      DataSource = DataModule1.NewbornsDS
    end
    object Label13: TLabel
      Left = 16
      Top = 184
      Width = 119
      Height = 13
      Caption = #1057#1074#1077#1076#1077#1085#1100#1103' '#1086' '#1088#1086#1076#1080#1090#1077#1083#1103#1093': '
    end
    object DBText2: TDBText
      Left = 48
      Top = 40
      Width = 42
      Height = 13
      AutoSize = True
      DataField = 'Sex'
      DataSource = DataModule1.NewbornsDS
    end
    object DBText3: TDBText
      Left = 104
      Top = 64
      Width = 42
      Height = 13
      AutoSize = True
    end
    object DBText4: TDBText
      Left = 112
      Top = 88
      Width = 42
      Height = 13
      AutoSize = True
    end
    object DBText5: TDBText
      Left = 96
      Top = 112
      Width = 42
      Height = 13
      AutoSize = True
      DataField = 'DateOfDeath'
      DataSource = DataModule1.DeadsDS
    end
    object DBText6: TDBText
      Left = 104
      Top = 136
      Width = 42
      Height = 13
      AutoSize = True
      DataField = 'PlaceOfDeath'
      DataSource = DataModule1.DeadsDS
    end
    object DBText7: TDBText
      Left = 112
      Top = 160
      Width = 42
      Height = 13
      AutoSize = True
      DataField = 'ReasonOfDeath'
      DataSource = DataModule1.DeadsDS
    end
    object DBText8: TDBText
      Left = 136
      Top = 184
      Width = 209
      Height = 161
      DataField = 'InformationAboutParents'
      DataSource = DataModule1.NewbornsDS
      WordWrap = True
    end
  end
  object MainMenu1: TMainMenu
    Top = 65532
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Action = Aopen
      end
      object N3: TMenuItem
        Action = Aexit
      end
    end
    object N4: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N6: TMenuItem
        Action = AopenRep
      end
      object N5: TMenuItem
        Action = Aguide
      end
    end
  end
  object ActionList1: TActionList
    Left = 32
    Top = 65532
    object Aopen: TAction
      Category = #1060#1072#1081#1083
      Caption = #1054#1090#1082#1088#1099#1090#1100
    end
    object Aexit: TAction
      Category = #1060#1072#1081#1083
      Caption = #1042#1099#1093#1086#1076
    end
    object AopenRep: TAction
      Category = #1057#1087#1088#1072#1074#1082#1072
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1086#1090#1095#1077#1090
    end
    object Aguide: TAction
      Category = #1057#1087#1088#1072#1074#1082#1072
      Caption = #1056#1091#1082#1086#1074#1086#1076#1089#1090#1074#1086
    end
  end
end
