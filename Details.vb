
Public Class frmDetails
    Private Sub btnRecord_Click(sender As Object, e As EventArgs) Handles btnRecord.Click
        validInputs(txtTitle.Text, txtAuthor.Text, txtStock.Text, txtPrice.Text)

        If frmBooks.valid Then
            'For updating books
            If txtTitle.Enabled = False And txtAuthor.Enabled = False Then
                frmBooks.myBook(frmBooks.n).stock = CInt(txtStock.Text)
                frmBooks.myBook(frmBooks.n).salePrice = CDbl(txtPrice.Text)
                If radFiction.Checked Then
                    frmBooks.myBook(frmBooks.n).category = "F"
                ElseIf radNonfiction.Checked Then
                    frmBooks.myBook(frmBooks.n).category = "N"
                End If
            Else 'For adding books
                frmBooks.myBook(frmBooks.numBooks).title = txtTitle.Text
                frmBooks.myBook(frmBooks.numBooks).author = txtAuthor.Text
                frmBooks.myBook(frmBooks.numBooks).stock = CInt(txtStock.Text)
                frmBooks.myBook(frmBooks.numBooks).salePrice = CDbl(txtPrice.Text)
                If radFiction.Checked Then
                    frmBooks.myBook(frmBooks.numBooks).category = "F"
                ElseIf radNonfiction.Checked Then
                    frmBooks.myBook(frmBooks.numBooks).category = "N"
                End If
            End If
            frmBooks.DisplayBooks()
            Me.Close()
        End If
    End Sub

    'checks if inputs are valid
    Sub validInputs(title As String, author As String, stock As String, price As String)
        If txtTitle.Text = "" Or txtAuthor.Text = "" Or IsNumeric(txtStock.Text) = False Or IsNumeric(txtPrice.Text) = False Then
            MessageBox.Show("Error: Invalid input")
            frmBooks.valid = False
        ElseIf CInt(txtStock.Text) <= 0 Or CDbl(txtPrice.Text) < 0 Then
            MessageBox.Show("Error: Invalid input")
            frmBooks.valid = False
        Else
            frmBooks.valid = True
        End If
    End Sub
End Class