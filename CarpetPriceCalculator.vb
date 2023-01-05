'Carpet Price Calculator
'Brian Jhon
'Dec. 4
'This program will calulate the price of carpets

Public Class frmCarpetPriceCalculator
    Dim myRectangle As New Rectangle
    Dim myCarpet As New Carpet

    'Gets Carpet Data
    Sub GetCarpetData()
        Try
            myCarpet.CarpetColor = txtColor.Text
            myCarpet.CarpetStyle = txtStyle.Text
            myCarpet.CarpetPrice = CDbl(txtPrice.Text)
        Catch
            MessageBox.Show("Invalid input, make sure to put valid numerals.a")
        End Try
    End Sub

    'Gets Rectangle Data
    Sub GetRoomData()
        Try
            myRectangle.W = CDbl(txtWidth.Text)
            myRectangle.L = CDbl(txtLength.Text)
        Catch
            MessageBox.Show("Invalid input, make sure to put valid numerals.b")
        End Try
    End Sub

    'Validates responses
    Function ValidResponse() As Boolean
        If myCarpet.CarpetColor = "" Or myCarpet.CarpetStyle = "" Then
            MessageBox.Show("Response left blank, make sure to input color and style.")
            Return False
        ElseIf myCarpet.CarpetPrice < 0 Or myRectangle.W < 0 Or myRectangle.L < 0 Then
            MessageBox.Show("Invalid input, make sure to put valid numerals.c")
            Return False
        Else
            Return True
        End If
    End Function

    'Calulates the area of the room and the price of the carpet
    Private Sub btnCalculate_Click(sender As Object, e As EventArgs) Handles btnCalculate.Click
        GetCarpetData()
        GetRoomData()

        If ValidResponse() Then
            myRectangle.CalcArea()
            lblArea.Text = (myRectangle.A).ToString("N") + "        "
            lblTotal.Text = (myRectangle.A * myCarpet.CarpetPrice).ToString("C") + "        "
        End If
    End Sub

    'Clears the form
    Private Sub btnClear_Click(sender As Object, e As EventArgs) Handles btnClear.Click
        txtColor.Clear()
        txtPrice.Clear()
        txtStyle.Clear()
        txtWidth.Clear()
        txtLength.Clear()
        lblArea.Text = "          "
        lblTotal.Text = "                "
        txtColor.Focus()
    End Sub

    'Exits Program
    Private Sub btnExit_Click(sender As Object, e As EventArgs) Handles btnExit.Click
        Me.Close()
    End Sub
End Class
