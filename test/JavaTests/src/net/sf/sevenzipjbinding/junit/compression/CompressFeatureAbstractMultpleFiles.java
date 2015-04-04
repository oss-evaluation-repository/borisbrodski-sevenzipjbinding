package net.sf.sevenzipjbinding.junit.compression;

import java.io.Closeable;

import net.sf.sevenzipjbinding.IOutCreateArchive;
import net.sf.sevenzipjbinding.IOutItemCallback;
import net.sf.sevenzipjbinding.SevenZip;
import net.sf.sevenzipjbinding.util.ByteArrayStream;

/**
 * Tests setting compression level.
 *
 * @author Boris Brodski
 * @version 9.13-2.00
 */
public abstract class CompressFeatureAbstractMultpleFiles extends CompressAbstractTest {

    protected IOutCreateArchive<IOutItemCallback> createArchive() throws Exception {
        IOutCreateArchive<IOutItemCallback> outArchive = SevenZip.openOutArchive(getArchiveFormat());
        addCloseable(outArchive);
        return outArchive;
    }

    protected void closeArchive(Closeable outArchive) throws Exception {
        removeCloseable(outArchive);
        outArchive.close();
    }

    protected void verifySingleFileArchive(ByteArrayStream outputByteArrayStream)
            throws Exception {
    }

}
