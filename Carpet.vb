Public Class Carpet
    Private Color As String
    Private Style As String
    Private Price As Double

    Public Sub newCarpet()
        CarpetColor = ""
        CarpetStyle = ""
        CarpetPrice = 0.0
    End Sub

    Public Property CarpetColor() As String
        Get
            Return Color
        End Get
        Set(value As String)
            Color = value
        End Set
    End Property

    Public Property CarpetStyle() As String
        Get
            Return Style
        End Get
        Set(value As String)
            Style = value
        End Set
    End Property

    Public Property CarpetPrice() As Double
        Get
            Return Price
        End Get
        Set(value As Double)
            Price = value
        End Set
    End Property
End Class
