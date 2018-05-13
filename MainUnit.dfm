object MainForm: TMainForm
  Left = 240
  Top = 309
  Width = 966
  Height = 640
  VertScrollBar.Position = 61
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 8
    Top = -13
    Width = 473
    Height = 345
    ActivePage = NewbornsSheet
    TabIndex = 0
    TabOrder = 0
    OnChange = PageControl1Change
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
        Columns = <
          item
            Expanded = False
            FieldName = 'FIO'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Sex'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'DateOfBirth'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'PlaceOfBirth'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'InformationAboutParents'
            Visible = True
          end>
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
        Columns = <
          item
            Expanded = False
            FieldName = 'FIO'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'Sex'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'DateOfBirth'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'PlaceOfBirth'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'DateOfDeath'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'PlaceOfDeath'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'ReasonOfDeath'
            Visible = True
          end>
      end
    end
  end
  object GroupBox: TGroupBox
    Left = 328
    Top = 355
    Width = 305
    Height = 465
    Caption = 'GroupBox'
    TabOrder = 1
    object Label1: TLabel
      Left = 16
      Top = 32
      Width = 136
      Height = 13
      Caption = #1060#1072#1084#1080#1083#1080#1103', '#1048#1084#1103', '#1054#1090#1095#1077#1089#1090#1074#1086': '
    end
    object Label2: TLabel
      Left = 16
      Top = 56
      Width = 26
      Height = 13
      Caption = #1055#1086#1083': '
    end
    object Label3: TLabel
      Left = 16
      Top = 80
      Width = 77
      Height = 13
      Caption = #1044#1072#1090#1072' '#1088#1086#1076#1077#1085#1080#1103': '
    end
    object Label4: TLabel
      Left = 16
      Top = 104
      Width = 91
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1088#1086#1078#1076#1077#1085#1080#1103': '
    end
    object Label5: TLabel
      Left = 16
      Top = 248
      Width = 119
      Height = 13
      Caption = #1057#1074#1077#1076#1077#1085#1100#1077' '#1086' '#1088#1086#1076#1080#1090#1077#1083#1103#1093': '
    end
    object Label14: TLabel
      Left = 16
      Top = 152
      Width = 72
      Height = 13
      Caption = #1044#1072#1090#1072' '#1089#1084#1077#1088#1090#1080': '
    end
    object Label15: TLabel
      Left = 16
      Top = 176
      Width = 78
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1089#1084#1077#1088#1090#1080': '
    end
    object Label16: TLabel
      Left = 16
      Top = 224
      Width = 89
      Height = 13
      Caption = #1055#1088#1080#1095#1080#1085#1072' '#1089#1084#1077#1088#1090#1080': '
    end
    object DBEdit1: TDBEdit
      Left = 160
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
      OnClick = DBEdit1Click
    end
    object DBEdit3: TDBEdit
      Left = 96
      Top = 72
      Width = 121
      Height = 21
      TabOrder = 1
      OnClick = DBEdit3Click
    end
    object DBEdit4: TDBEdit
      Left = 16
      Top = 120
      Width = 281
      Height = 21
      TabOrder = 2
      OnClick = DBEdit4Click
    end
    object DBEdit5: TDBEdit
      Left = 88
      Top = 144
      Width = 121
      Height = 21
      DataField = 'DateOfBirth'
      DataSource = DataModule1.DeadsDS
      TabOrder = 3
      OnClick = DBEdit5Click
    end
    object DBEdit6: TDBEdit
      Left = 16
      Top = 192
      Width = 273
      Height = 21
      DataField = 'PlaceOfDeath'
      DataSource = DataModule1.DeadsDS
      TabOrder = 4
      OnClick = DBEdit6Click
    end
    object DBMemo1: TDBMemo
      Left = 16
      Top = 264
      Width = 281
      Height = 145
      DataField = 'InformationAboutParents'
      DataSource = DataModule1.NewbornsDS
      TabOrder = 5
      OnClick = DBMemo1Click
    end
    object DBEdit7: TDBEdit
      Left = 104
      Top = 216
      Width = 185
      Height = 21
      DataField = 'ReasonOfDeath'
      DataSource = DataModule1.DeadsDS
      TabOrder = 6
      OnClick = DBEdit7Click
    end
    object CancelButton: TButton
      Left = 8
      Top = 432
      Width = 75
      Height = 25
      Caption = 'CancelButton'
      TabOrder = 7
      OnClick = CancelButtonClick
    end
    object ConfirmButton: TButton
      Left = 224
      Top = 432
      Width = 75
      Height = 25
      Caption = 'ConfirmButton'
      TabOrder = 8
      OnClick = ConfirmButtonClick
    end
    object DBComboBox1: TDBComboBox
      Left = 48
      Top = 48
      Width = 145
      Height = 21
      Style = csDropDownList
      ItemHeight = 13
      TabOrder = 9
      OnClick = DBComboBox1Click
    end
  end
  object AddButton: TButton
    Left = 24
    Top = 363
    Width = 75
    Height = 25
    Caption = 'AddButton'
    TabOrder = 2
    OnClick = AddButtonClick
  end
  object EditButton: TButton
    Left = 120
    Top = 363
    Width = 75
    Height = 25
    Caption = 'EditButton'
    TabOrder = 3
    OnClick = EditButtonClick
  end
  object DeleteButton: TButton
    Left = 216
    Top = 363
    Width = 75
    Height = 25
    Caption = 'DeleteButton'
    TabOrder = 4
    OnClick = DeleteButtonClick
  end
  object InformationPanel: TPanel
    Left = 520
    Top = -25
    Width = 369
    Height = 377
    Caption = 'InformationPanel'
    TabOrder = 5
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
      Left = 16
      Top = 208
      Width = 345
      Height = 145
      DataField = 'InformationAboutParents'
      DataSource = DataModule1.NewbornsDS
      WordWrap = True
    end
  end
  object MainMenu1: TMainMenu
    Top = 65535
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
    Left = 40
    Top = 65535
    object Aopen: TAction
      Category = #1060#1072#1081#1083
      Caption = #1054#1090#1082#1088#1099#1090#1100
      OnExecute = AopenExecute
    end
    object Aexit: TAction
      Category = #1060#1072#1081#1083
      Caption = #1042#1099#1093#1086#1076
      OnExecute = AexitExecute
    end
    object AopenRep: TAction
      Category = #1057#1087#1088#1072#1074#1082#1072
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1086#1090#1095#1077#1090
      OnExecute = AopenRepExecute
    end
    object Aguide: TAction
      Category = #1057#1087#1088#1072#1074#1082#1072
      Caption = #1056#1091#1082#1086#1074#1086#1076#1089#1090#1074#1086
    end
  end
end
