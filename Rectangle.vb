Public Class Rectangle
    Private Width As Double
    Private Length As Double
    Private Area As Double

    Public Sub newRectangle()
        W = 0.0
        L = 0.0
        CalcArea()
    End Sub

    Public Property W() As Double
        Get
            Return Width
        End Get
        Set(value As Double)
            Width = value
        End Set
    End Property

    Public Property L() As Double
        Get
            Return Length
        End Get
        Set(value As Double)
            Length = value
        End Set
    End Property

    Public ReadOnly Property A() As Double
        Get
            Return Area
        End Get
    End Property

    Sub CalcArea()
        Area = Length * Width
    End Sub
End Class
