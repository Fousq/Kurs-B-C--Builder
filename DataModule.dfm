object DataModule1: TDataModule1
  OldCreateOrder = False
  Left = 480
  Top = 387
  Height = 264
  Width = 286
  object NewbornsDS: TDataSource
    DataSet = NewbornsTable
    Left = 40
    Top = 80
  end
  object DeadsDS: TDataSource
    DataSet = DeadsTable
    Left = 112
    Top = 80
  end
  object NewbornsTable: TTable
    DatabaseName = 'Records'
    TableName = 'Newborns.DB'
    Left = 48
    Top = 24
  end
  object DeadsTable: TTable
    DatabaseName = 'Records'
    TableName = 'Deads.db'
    Left = 120
    Top = 24
  end
end
