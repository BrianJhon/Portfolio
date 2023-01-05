'Books
'Brian Jhon
'November 10
'This Program will perform actions for a list of books from a text file

Public Class frmBooks

    Structure Books
        Dim title As String
        Dim author As String
        Dim category As String
        Dim stock As Integer
        Dim salePrice As Double
    End Structure

    'Class level variables
    Public myBook(12) As Books
    Public valid As Boolean = False
    Public numBooks As Integer = 12
    Public n As Integer
    Dim readFile(12) As String
    Dim swFile As IO.StreamWriter

    'Loads content of Books text file into array structure and displays tittles of books in inventory
    Private Sub frmBooks_Load() Handles MyBase.Load
        'Catches file not found exception
        Try
            readFile = IO.File.ReadAllLines("Books.txt")
        Catch
            MessageBox.Show("Books.txt not found.")
            Me.Close()
        End Try

        For i As Integer = 0 To numBooks
            myBook(i).title = readFile(i).Split(","c)(0)
            myBook(i).author = readFile(i).Split(","c)(1)
            myBook(i).category = readFile(i).Split(","c)(2)
            myBook(i).stock = CInt(readFile(i).Split(","c)(3))
            myBook(i).salePrice = CDbl(readFile(i).Split(","c)(4))
            lstBooks.Items.Add(myBook(i).title)
        Next
    End Sub

    'Displays all books that are in the invetory
    Private Sub mnuDisplayAll_Click(sender As Object, e As EventArgs) Handles mnuDisplayAll.Click
        mnuDisplayAll.Checked = True
        mnuDisplayFiction.Checked = False
        mnuDisplayNonfiction.Checked = False
        DisplayBooks()
    End Sub

    'Display fictional books
    Private Sub mnuDisplayFiction_Click(sender As Object, e As EventArgs) Handles mnuDisplayFiction.Click
        mnuDisplayAll.Checked = False
        mnuDisplayFiction.Checked = True
        mnuDisplayNonfiction.Checked = False
        DisplayBooks()
    End Sub

    'Displays nonfictional books
    Private Sub mnuDisplayNonfiction_Click(sender As Object, e As EventArgs) Handles mnuDisplayNonfiction.Click
        mnuDisplayAll.Checked = False
        mnuDisplayFiction.Checked = False
        mnuDisplayNonfiction.Checked = True
        DisplayBooks()
    End Sub

    'Displays books
    Sub DisplayBooks()
        lstBooks.Items.Clear()
        If mnuDisplayAll.Checked Then 'Display all
            For i As Integer = 0 To numBooks
                lstBooks.Items.Add(myBook(i).title)
            Next
        ElseIf mnuDisplayFiction.Checked Then 'Display fiction
            For i As Integer = 0 To numBooks
                If myBook(i).category = "F" Then
                    lstBooks.Items.Add(myBook(i).title)
                End If
            Next
        ElseIf mnuDisplayNonfiction.Checked Then 'Display nonfiction
            For i As Integer = 0 To numBooks
                If myBook(i).category = "N" Then
                    lstBooks.Items.Add(myBook(i).title)
                End If
            Next
        End If
    End Sub


    'Displays a message box showing the value of all books
    Private Sub mnuValuesAll_Click(sender As Object, e As EventArgs) Handles mnuValuesAll.Click
        Dim total As Double = 0
        For i As Integer = 0 To numBooks
            total = total + myBook(i).stock * myBook(i).salePrice
        Next
        MessageBox.Show("Value: " + total.ToString("c"), "All")

    End Sub

    'Displays a message box showing the value of all fiction books
    Private Sub mnuValuesFiction_Click(sender As Object, e As EventArgs) Handles mnuValuesFiction.Click
        Dim total As Double = 0
        For i As Integer = 0 To numBooks
            If myBook(i).category = "F" Then
                total = total + myBook(i).stock * myBook(i).salePrice
            End If
        Next
        MessageBox.Show("Value: " + total.ToString("c"), "Fiction")
    End Sub

    'Displays a message box showing the price of all nonfiction books
    Private Sub mnuValuesNonfiction_Click(sender As Object, e As EventArgs) Handles mnuValuesNonfiction.Click
        Dim total As Double = 0
        For i As Integer = 0 To numBooks
            If myBook(i).category = "N" Then
                total = total + myBook(i).stock * myBook(i).salePrice
            End If
        Next
        MessageBox.Show("Value: " + total.ToString("c"), "Nonfiction")
    End Sub

    'Adds a book to the invetory
    Private Sub mnuBookAdd_Click(sender As Object, e As EventArgs) Handles mnuBookAdd.Click
        numBooks += 1
        ReDim Preserve myBook(numBooks)
        frmDetails.Show()

    End Sub

    'Delets a book from the list
    Private Sub mnuBookDelete_Click(sender As Object, e As EventArgs) Handles mnuBookDelete.Click

        If lstBooks.SelectedIndex = -1 Then
            MessageBox.Show("Please select a book from the list to delete.")
        Else
            Dim titleToDelete As String = CStr(lstBooks.SelectedItem) 'can select book in Display options all,fiction, or nonfiction
            For i As Integer = 0 To numBooks
                If myBook(i).title = titleToDelete Then
                    n = i
                End If
            Next

            For i As Integer = n To numBooks - 1
                myBook(i).title = myBook(i + 1).title
                myBook(i).author = myBook(i + 1).author
                myBook(i).category = myBook(i + 1).category
                myBook(i).stock = myBook(i + 1).stock
                myBook(i).salePrice = myBook(i + 1).salePrice
            Next
            numBooks -= 1
            ReDim Preserve myBook(numBooks)
            DisplayBooks()
        End If
    End Sub

    'Updates an existing book from the list
    Private Sub mnuBookUpdate_Click(sender As Object, e As EventArgs) Handles mnuBookUpdate.Click
        If lstBooks.SelectedIndex = -1 Then
            MessageBox.Show("Please select a book from the list to delete.")
        Else
            Dim titleToDelete As String = CStr(lstBooks.SelectedItem) 'can select book in Display options all,fiction, or nonfiction
            For i As Integer = 0 To numBooks
                If myBook(i).title = titleToDelete Then
                    n = i
                End If
            Next

            frmDetails.txtTitle.Text = myBook(n).title
            frmDetails.txtAuthor.Text = myBook(n).author
            frmDetails.txtTitle.Enabled = False
            frmDetails.txtAuthor.Enabled = False
            frmDetails.Show()

        End If
    End Sub

    'Saves structure array to text file "Books"
    Private Sub mnuFileSave_Click(sender As Object, e As EventArgs) Handles mnuFileSave.Click
        'Catches file not found exception
        Try
            swFile = IO.File.CreateText("Books.txt")
        Catch
            MessageBox.Show("Books.txt not found.")
            Me.Close()
        End Try

        For i As Integer = 0 To numBooks
            swFile.WriteLine(myBook(i).title + "," + myBook(i).author + "," + myBook(i).category + "," + CStr(myBook(i).stock) + "," + CStr(myBook(i).salePrice))
        Next
        swFile.Close()
        MessageBox.Show("File saved.")
    End Sub

    'Exits Program
    Private Sub mnuFileExit_Click(sender As Object, e As EventArgs) Handles mnuFileExit.Click
        Me.Close()
    End Sub
End Class
