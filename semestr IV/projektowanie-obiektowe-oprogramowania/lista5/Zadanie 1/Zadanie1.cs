public interface SmtpFacade {
	
	public void Send(string From, string To,
		string Subject, string Body,
		Stream Attachment, string AttachmentMimeType);
		
}

public class SmtpFacade
{
    public void Send (string From, string To, string Subject, string Body, Stream Attachment, string AttachmentMimeType);
    {
        SmtpClient smtpClient = new SmtpClient();
        smtpClient.Host = "smtp.outlook.com";
        smtpClient.Port = 587;
        smtpClient.EnableSsl = true;
        smtpClient.Credentials = new NetworkCredential(From, "password");

        MailMessage mailMessage = new MailMessage(From, To, Subject, Body);

        Attachment attachment = new Attachment (Attachment, AttachmentMimeType);
        mailMessage.AttachmentMimeType.Add(attachment);

        smtpClient.Send(mailMessage);
    }
 
}